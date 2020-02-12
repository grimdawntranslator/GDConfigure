#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include "grimdawn.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    GrimDawn *gd;
    bool hasError;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Show();

private slots:
    void on_ShowMessage(QString message);
    void on_ShowError(QString errstr, bool dialog=false);
    void on_GDInfoLoadded();
    void on_pushButton_Apply_clicked();
    void on_comboBox_Languages_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
