#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QSqlTableModel>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "homework_01_01_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    QTcpServer server;
    QTcpSocket socket;

    QSqlDatabase db;
    QSqlTableModel model;


    return a.exec();
}
