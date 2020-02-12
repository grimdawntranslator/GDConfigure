#include <QCoreApplication>
#include <QString>
#include <QSettings>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <qlogging.h>

#include "utils.h"
#include "grimdawn.h"

#define ShellFolders "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders"

GrimDawn::GrimDawn(QObject *parent) : QObject(parent), _SupportFonts({ "en", "bg", "cs", "de", "el", "es", "fr", "hu", "it", "ja", "ko", "nl", "pl", "pt", "ru", "sk", "th", "tr", "tt", "vi", "zh" })
{
    SettingKeyMaxLen = 0;
    _JobExtractHasError = false;
    _JobPackageHasError = false;

#if defined (DEBUG_MODE)
    _GamePath = QDir::currentPath();
    _SettingPath = QString("%1/%2").arg(_GamePath).arg("settings");
#else
    _GamePath = QCoreApplication::applicationDirPath();
    // _GamePath = QDir::currentPath();
    QSettings reg(ShellFolders, QSettings::NativeFormat);
    QString personal = reg.value("Personal").toString();
    _SettingPath = QString("%1/%2/%3/%4").arg(personal).arg("My Games").arg("Grim Dawn").arg("Settings");
#endif
    _LanguagePath = QString("%1/%2").arg(_GamePath).arg("localization");

    qDebug() << "Work Path:" << _GamePath;
    qDebug() << "Setting Path:" << _SettingPath;
    qDebug() << "Language Path:" << _LanguagePath;
}

GrimDawn::~GrimDawn()
{
    if (!_Fonts.isEmpty())
        _Fonts.clear();
    if (!_Languages.isEmpty())
        _Languages.clear();
    if (!_Settings.isEmpty())
        _Settings.clear();
    if (!_SettingKeys.isEmpty())
        _SettingKeys.clear();
    if (!_jobs.isEmpty()) {
        foreach(Job* job, _jobs.values()) {
            if (job->state() != QProcess::NotRunning)
                job->kill();
            delete job;
        }
        _jobs.clear();
    }
}

// Private
void GrimDawn::loadSettings()
{
    QDir dir(_SettingPath);
    if (!dir.exists("options.txt"))
        return;

    QFile file(dir.absoluteFilePath("options.txt"));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString contents = file.readAll();
    file.close();

    QStringList lines = contents.split("\n");

    _SettingKeys.clear();
    _Settings.clear();
    foreach (QString line, lines) {
        if (line.length() <= 0) continue;

        QStringList keyvalue = line.split(" = ");
        if (keyvalue.length() == 2) {
            QString key = keyvalue[0];
            QString value = keyvalue[1].trimmed();
            SettingKeyMaxLen = MAX(SettingKeyMaxLen, key.length());
            key = key.trimmed();

            _Settings.insert(key, value);
            _SettingKeys.append(key);
        } else {
            qDebug() << "::::Line:" << line;
        }
    }
    QString languageName = Strip(_Settings.value("language", "English"));
    _Language.language = languageName;
    if (_Language.language == "English")
        _Language.font = "en";

    qDebug() << "Language:" << languageName;
}

void GrimDawn::loadLanguages()
{
    QDir dir(_LanguagePath, "*.zip");
    if (!dir.exists() || dir.isEmpty()) {
        _Language.file = "English";
        _Language.basename = "English";
        _Language.language = "English";
        _Language.font = "en";
    } else {
        foreach (QString file, dir.entryList()) {
#if defined(DEBUG_MODE)
            qDebug() << "Localization file:" << file;
#endif
            GDLanguage language;
            language.file = file;
            language.basename = file.chopped(QString(".zip").length());
            extractLanguageInfo(file);
            _Languages.append(language);
        }
    }
}

void GrimDawn::loadFonts()
{
    QDir dir(QString("%1/%2").arg(_GamePath).arg("settings"));

    foreach (QString font, _SupportFonts) {
        _Fonts.insert(font, "");
    }

    if (!dir.exists("fonts"))
        return;

    dir.cd("fonts");
    if (dir.isEmpty(QDir::Dirs|QDir::NoDot|QDir::NoDotDot))
        return;

    foreach (QString font, dir.entryList(QDir::Dirs|QDir::NoDot|QDir::NoDotDot)) {
#if defined (DEBUG_MODE)
        qDebug() << "Font folder:" << font;
#endif
        if (_SupportFonts.contains(font.toLower())) {
            QDir sub(dir.absoluteFilePath(font), "*.fnt");
            if (!sub.isEmpty()) {
                _Fonts[font.toLower()] = QString("setting/font/%1").arg(font);
            }
        }
    }
}

void GrimDawn::updateLanguagesInfo(const QString &zipfile)
{
    GDLanguage *language = nullptr;
    for (int i=0; i<_Languages.length(); i++) {
        if (_Languages[i].file == zipfile)
            language = &_Languages[i];
    }

    QString def = QString("%1/%2/%3").arg(_LanguagePath).arg(language->basename).arg("language.def");
#if defined (DEBUG_MODE)
     qDebug() << "Language Def:" << def;
#endif

    QFile file(def);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QString contents = file.readAll();
    file.close();

    QStringList lines = contents.split("\n");

    foreach (QString line, lines) {
        if (line.length() <= 0) continue;
        QStringList keyvalue = line.split("=");
        if (keyvalue.length() == 2) {
            QString key = keyvalue[0].trimmed();
            QString value = keyvalue[1].trimmed();
            if (key.toLower() == "language")
                language->language = value;
            if (key.toLower() == "author")
                language->author = value.split(" ");
            if (key.toLower() == "version")
                language->version = value;
            if (key.toLower() == "fonts")
                language->font = value;
            if (key.toLower() == "separators")
                language->separators = value;
            if (key.toLower() == "wordmode")
                language->wordmode = value.toLower()=="true"?true:false;
        } else {
            qDebug() << "::::Line:" << line;
        }
    }

    if (_Language.language == language->language) {
        _Language = *language;
    }
}

bool GrimDawn::CheckExistLanguage()
{
    for (int i=0; i+1<_Languages.size(); i++) {
#if defined (DEBUG_MODE)
        qDebug() << "CheckExistLanguage:" << _Languages.at(i).file;
#endif
        for (int j=i+1; j < _Languages.size(); j++) {
#if defined (DEBUG_MODE)
            qDebug() << "CheckExistLanguage:" << _Languages.at(i).file << "Compare:" << _Languages.at(j).file;
#endif
            if (_Languages.at(i).language == _Languages.at(j).language) {
                QStringList errs;
                errs.clear();
                errs.append(tr("The following files have the same Language Name!"));
                errs.append("");
                errs.append(tr("Language Name:"));
                errs.append("    " + _Languages.at(i).language);
                errs.append("");
                errs.append(tr("Files:"));
                errs.append("    " + _Languages.at(i).file);
                errs.append("    " + _Languages.at(j).file);

                emit error(errs.join("\n"), true);

                return false;
            }
        }
    }

    return true;
}

void GrimDawn::CheckJobs(JobType type)
{
    if (_jobs.isEmpty()) {
#if defined (DEBUG_MODE)
        qDebug() << "AllJobs done!";
#endif
        if (_JobExtractHasError || _JobPackageHasError) {
            emit error(tr("Failed!"), false);
            emit failed();
        } else {
            CheckExistLanguage();
            switch (type)
            {
            case JobExtract:
                qDebug() << "Font:" << _Language.font;
                break;
            case JobPackage:
                break;
            }
            emit finished();
        }
    }
}

void GrimDawn::doJob(JobType type, const QString &file, const QStringList &args)
{
    Job *job = nullptr;

    if (!_jobs.contains(file)) {
        job = new Job(type, file, this);
        job->setProcessChannelMode(QProcess::MergedChannels);
        connect(job, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(JobFinished(int, QProcess::ExitStatus)));
        connect(job, SIGNAL(error(QProcess::ProcessError)), this, SLOT(JobFailed(QProcess::ProcessError)));

        _jobs.insert(file, job);
    } else {
        job = _jobs.value(file);
        if (job->state() != QProcess::NotRunning) {
            qDebug() << "Extracting File:" << file;
            return;
        }
    }

    QString cmd = QString("%1/%2").arg(_GamePath).arg("7z.exe");

//    qDebug() << "Job:" << cmd << args;

    job->start(cmd, args);
}

void GrimDawn::extractLanguageInfo(const QString &file)
{
    QDir dir(_LanguagePath);
    QFileInfo fi(dir, file);
    QStringList args;
    args << "e";
    args << "-y";
    args << QString("-o%1/%2").arg(_LanguagePath).arg(fi.baseName());
    args << fi.filePath();
    args << "language.def";

    _JobExtractHasError = false;
    doJob(JobExtract, file, args);
}

void GrimDawn::packageLanguageInfo(const QString &file)
{
    QDir dir(_LanguagePath);
    QFileInfo fi(dir, file);
    QStringList args;
    args << "a";
    args << "-y";
    args << fi.filePath();
    args << QString("%1/%2/%3").arg(_LanguagePath).arg(fi.baseName()).arg("language.def");

    _JobPackageHasError = false;
    doJob(JobPackage, file, args);
}

// Public
bool GrimDawn::isGamePathVaild()
{
    QDir dir(_GamePath);
    QFileInfo fi;
    fi.setFile(dir, "Grim Dawn.exe");
    if (!fi.isExecutable())
        return false;
    fi.setFile(dir, "database");
    if (!fi.isDir())
        return false;

    return true;
}

bool GrimDawn::isGrimDawnRunning()
{
    // TODO: need implement
    return false;
}

void GrimDawn::loadGDInfo()
{
    loadSettings();
    loadLanguages();
    loadFonts();
}

void GrimDawn::setGDLanguage(const QString &zipfile)
{
    qDebug() << "Set Language to:" << zipfile;

    if (zipfile == "English" && _Language.language != zipfile) {
        _Language.file = zipfile;
        _Language.basename = zipfile;
        _Language.language = zipfile;
        _Language.font = "en";
    } else {
        foreach (GDLanguage language, _Languages) {
            if (language.file == zipfile) {
                _Language = language;
            }
        }
    }
    _Settings["language"] = QString("\"%1\"").arg(_Language.language);

    QDir dir(_SettingPath);
    if (!dir.exists())
        dir.mkpath(dir.absolutePath());
    QFile file(dir.absoluteFilePath("options.txt"));
    file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    QStringList lines = {};
    foreach (QString key, _SettingKeys) {
        if (_Settings.contains(key)) {
            QString save_key = key.leftJustified(SettingKeyMaxLen-1);
            QString save_value = _Settings.value(key);
            if (save_value.isEmpty())
                save_value = "\"\"";
            QString line = QString("%1 = %2").arg(save_key).arg(save_value);
            lines.append(line);
        }
    }

    QString contents = lines.join('\n') + "\n";
    file.write(contents.toUtf8());
    file.flush();

    file.close();
}

void GrimDawn::setGDFont(const QString &font)
{
    if (font.toLower() == "en") {
        emit message(tr("OK!"));
        emit finished();
        return;
    }

    qDebug() << "Set Font to:" << font;
    if (_SupportFonts.contains(font))
        _Language.font = font.toLower();

    QString def = QString("%1/%2/%3").arg(_LanguagePath).arg(_Language.basename).arg("language.def");

    QFile file(def);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);

    QStringList lines = {};
    lines.append(QString("Language=%1").arg(_Language.language));
    lines.append(QString("Author=%1").arg(_Language.author.join(" ")));
    lines.append(QString("Version=%1").arg(_Language.version));
    lines.append(QString("Fonts=%1").arg(_Language.font.toUpper()));
    lines.append(QString("Separators=%1").arg(_Language.separators));
    lines.append(QString("Wordmode=%1").arg(_Language.wordmode?"true":"false"));

    QString contents = lines.join('\n') + "\n";
    file.write(contents.toUtf8());
    file.flush();

    file.close();

    packageLanguageInfo(_Language.file);
}

void GrimDawn::showGDLanguageInfo(GDLanguage &language)
{
    qDebug() << "Language:" << language.language;
    qDebug() << "      Author:" << language.author.join(" ");
    qDebug() << "        File:" << language.file;
    qDebug() << "    Basename:" << language.basename;
    qDebug() << "        Font:" << language.font;
    qDebug() << "  Separators:" << language.separators;
    qDebug() << "   Word Mode:" << language.wordmode;
}

// Private Slots
void GrimDawn::JobFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    Q_UNUSED(exitCode)
    Q_UNUSED(exitStatus)

    Job *job = static_cast<Job*>(sender());
    JobType type = job->type();

    switch (type)
    {
    case JobExtract:
#if defined (DEBUG_MODE)
        qDebug() << "JobExtract Finished";
#endif
        updateLanguagesInfo(job->name());
        break;
    case JobPackage:
#if defined (DEBUG_MODE)
        qDebug() << "JobPackage Finished";
#endif
        emit message(tr("OK!"));
        break;
    }
    emit JobFinished(type);

    _jobs.remove(job->name());
    delete job;

    CheckJobs(type);
}

void GrimDawn::JobFailed(QProcess::ProcessError error)
{
    Job *job = static_cast<Job*>(sender());
    JobType type = job->type();

    switch (type)
    {
    case JobExtract:
        _JobExtractHasError = true;
        qCritical() << "Error: JobExtract" << job->name() << error;
        break;
    case JobPackage:
        _JobPackageHasError = true;
        qCritical() << "Error: JobPackage" << job->name() << error;
        break;
    }
    emit JobFailed(type);

    _jobs.remove(job->name());
    delete job;

    CheckJobs(type);
}
