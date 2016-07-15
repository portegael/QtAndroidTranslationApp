#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include <QTranslator>
#include <QDebug>
#include <QGuiApplication>

class Translation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)

public:
    explicit Translation(QObject *parent = 0);
    QString getEmptyString() { return ""; }

    Q_INVOKABLE void selectLanguage(QString language);

signals:
    void languageChanged();

private:
    QGuiApplication *m_application;
    QTranslator *m_translator;
};

#endif // TRANSLATION_H
