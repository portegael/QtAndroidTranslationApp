#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTranslator>
#include <QDebug>
#include <QQmlContext>

#include "translation.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QTranslator translator;
    Translation *translateObj = new Translation((QObject*)&app);

    qDebug() << translator.load(":/translations/language_fr");
    app.installTranslator(&translator);

    engine.rootContext()->setContextProperty("translateItem", (QObject*)translateObj);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

