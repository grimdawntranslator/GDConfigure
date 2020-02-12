#ifndef GRIMDAWN_H
#define GRIMDAWN_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QHash>
#include <QMap>
#include <QList>

#include "Job.h"

struct GDLanguage
{
    QString file;
    QString basename;
    QString language;
    QList<QString> author;
    QString version;
    QString font;
    QString separators;
    bool wordmode;
};

enum FontsType {
    InnerFonts = 0,
    ArcFonts,
    SettingsFonts,
};

class GrimDawn : public QObject
{
    Q_OBJECT

    QString _GamePath;
    QString _SettingPath;
    QString _LanguagePath;

    const QStringList _SupportFonts;

    GDLanguage _Language;

    QList<GDLanguage> _Languages;
    // Fonts: <Font, Path>
    QMap<QString,QString> _Fonts;
    // Settings: <Key, Value>
    QHash<QString,QString> _Settings;
    QStringList _SettingKeys;
    int SettingKeyMaxLen;

    bool _JobExtractHasError;
    bool _JobPackageHasError;
    QHash<QString, Job*> _jobs;

    void loadSettings();
    void loadLanguages();
    void loadFonts();

    void updateLanguagesInfo(const QString &zipfile);

    bool CheckExistLanguage();
    void CheckJobs(JobType type);
    void doJob(JobType type, const QString &file, const QStringList &args);
    void extractLanguageInfo(const QString &file);
    void packageLanguageInfo(const QString &file);

public:
    explicit GrimDawn(QObject *parent = nullptr);
    ~GrimDawn();

    const QString& GamePath() const { return _GamePath; }
    const GDLanguage& Language() const { return _Language; }
    const QString& LangPath() const { return _LanguagePath; }
    const QList<GDLanguage>& Languages() const { return _Languages; }
    const QMap<QString,QString>& Fonts() const { return _Fonts; }

    bool isGamePathVaild();
    bool isGrimDawnRunning();

    void loadGDInfo();

    void setGDLanguage(const QString &zipfile);
    void setGDFont(const QString &font);

    void showGDLanguageInfo(GDLanguage &language);

signals:
    void message(QString message);
    void error(QString errstr, bool dialog=false);
    void JobFinished(JobType type);
    void JobFailed(JobType type);
    void finished();
    void failed();

private slots:
    void JobFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void JobFailed(QProcess::ProcessError error);
};

#endif // GRIMDAWN_H
