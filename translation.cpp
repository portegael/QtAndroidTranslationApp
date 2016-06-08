#include "translation.h"

Translation::Translation(QObject *parent) : QObject(parent)
{
    m_application = (QGuiApplication*)parent;
}

/*
 * Method called from QML to select a new language
 */
void Translation::selectLanguage(QString language)
{
    QTranslator qtTranslator;

    QString newLanguage = ":/translations/language_" + language.toLower();

    if( qtTranslator.load(newLanguage) && m_application != NULL)
    {
        m_application->installTranslator(&qtTranslator);
        emit languageChanged();
    }
    else
    {
        qWarning() << "Cannot load the file " << newLanguage;
    }

}
