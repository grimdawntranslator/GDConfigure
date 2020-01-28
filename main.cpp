#include "mainwindow.h"

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif
#include <QTextCodec>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QTranslator *translator = new QTranslator;
    translator->load(":/locale/GDConfigure_zh_CN.qm");
    a.installTranslator(translator);

    MainWindow w;
    w.show();
    return a.exec();
}
