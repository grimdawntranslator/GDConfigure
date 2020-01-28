#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gd = new GrimDawn();
    connect(gd, SIGNAL(finished()), this, SLOT(on_GDInfoLoadded()));
    connect(gd, SIGNAL(message(QString)), this, SLOT(on_ShowMessage(QString)));
    gd->loadGDInfo();

    ui->pushButton_Apply->setDisabled(!gd->isGamePathVaild() | gd->isGrimDawnRunning());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ShowMessage(QString message)
{
    if (message.isEmpty())
        ui->label_Messages->setText("");
    else
        ui->label_Messages->setText(message);
}

void MainWindow::on_GDInfoLoadded()
{
    QString GamePath = gd->GamePath();
    ui->label_GamePath->setText(GamePath.replace('/', '\\'));
    ui->label_Language->setText(gd->Language().language);
    ui->label_Font->setText(gd->Language().font.toLower());

    // Languages
    ui->comboBox_Languages->clear();
    ui->comboBox_Languages->addItem(tr("English (US)"), "English");
    foreach (GDLanguage language, gd->Languages()) {
        ui->comboBox_Languages->addItem(language.language, language.file);
    }
    ui->comboBox_Languages->setCurrentText(gd->Language().language);

    // Fonts
    ui->comboBox_Fonts->clear();
    if (!gd->Fonts().isEmpty()) {
        QMap<QString,QString>::const_iterator iter = gd->Fonts().constBegin();
        while (iter != gd->Fonts().constEnd()) {
            QString font;
            if (iter.value().isEmpty())
                font = iter.key();
            else
                font = QString("%1 (%2)").arg(iter.key()).arg(iter.value());

            ui->comboBox_Fonts->addItem(font, iter.key());

            ++iter;
        }
    }
    int iFont = ui->comboBox_Fonts->findText(gd->Language().font.toLower(), Qt::MatchStartsWith);
    if (iFont > 0 && iFont < ui->comboBox_Fonts->count())
        ui->comboBox_Fonts->setCurrentIndex(iFont);
}

void MainWindow::on_pushButton_Apply_clicked()
{
    ui->label_Messages->clear();

    gd->setGDLanguage(ui->comboBox_Languages->currentData().toString());

    if (ui->comboBox_Languages->currentData().toString() == "English")
        gd->setGDFont("en");
    else
        gd->setGDFont(ui->comboBox_Fonts->currentData().toString());
}

void MainWindow::on_comboBox_Languages_currentIndexChanged(int index)
{
    Q_UNUSED(index)

    QString data = ui->comboBox_Languages->currentData().toString();
    if (data == "English") {
        ui->comboBox_Fonts->setEnabled(false);
        ui->comboBox_Fonts->setCurrentText("en");
    } else {
        ui->comboBox_Fonts->setEnabled(true);
        foreach (GDLanguage language, gd->Languages()) {
            if (language.file == data) {
                int iFont = ui->comboBox_Fonts->findText(language.font.toLower(), Qt::MatchStartsWith);
                if (iFont > 0 && iFont < ui->comboBox_Fonts->count())
                    ui->comboBox_Fonts->setCurrentIndex(iFont);
                break;
            }
        }
    }
}
