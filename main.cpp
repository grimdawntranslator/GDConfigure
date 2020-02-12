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
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QTranslator *translator = new QTranslator;
    translator->load(":/locale/GDConfigure_zh_CN.qm");
    a.installTranslator(translator);

    MainWindow w;
    w.Show();
    return a.exec();
}
