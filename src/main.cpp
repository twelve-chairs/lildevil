#include "main.h"

int main(int argc, char *argv[])
{
    enum window {
        windowWidth = 1200,
        windowHeight = 800
    };

    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("Twelve Chairs Software, LLC");
    QCoreApplication::setOrganizationDomain("twelvechairs-software.com");
    QCoreApplication::setApplicationName("lilDevil");

    QSettings settings;

    QScreen *desktop = QGuiApplication::primaryScreen();
    QRect screenGeometry = desktop->geometry();

    MainWindow w;
    w.resize(window::windowWidth, window::windowHeight);
    w.move((screenGeometry.width() - window::windowWidth) / 2, (screenGeometry.height() - window::windowHeight) / 2);
    w.show();

    return QApplication::exec();
}
