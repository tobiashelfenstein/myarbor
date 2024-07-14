#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // include global style sheets
    QFile f("/home/tobias/projects/myArbor/styles.qss");
    f.open(QFile::ReadOnly);
    QString styles = QLatin1String(f.readAll());

    a.setStyleSheet(styles);

    MainWindow w;
    w.show();

    return a.exec();
}
