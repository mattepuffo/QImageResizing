#include "mainwindow.h"
#include "imageresize.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    /*QCoreApplication::setOrganizationName("Mattepuffo");
    QCoreApplication::setOrganizationDomain("com.mp.qresizeimage");
    QCoreApplication::setApplicationName("QImageResize");
    QCoreApplication::setApplicationVersion("0.1.5");*/
    QApplication a(argc, argv);
    qApp->setOrganizationName(ORG_NAME);
    qApp->setOrganizationDomain(ORG_DOMAIN);
    qApp->setApplicationName(APP_NAME);
    qApp->setApplicationVersion(APP_VERSION);
    MainWindow w;
    w.show();
    return a.exec();
}
