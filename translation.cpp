#include "translation.h"

Translation::Translation(QObject *parent) : QObject(parent);
    m_language("en")
{
    m_translator = new QTranslator(this);
    m_application = (QGuiApplication*)parent;
}

/*
 * Method called from QML to select a new language
 */
void Translation::selectLanguage(QString language)
{
if(language != m_language)
    {
        QString newLanguage = ":/translations/language_" + language.toLower();

        m_application->removeTranslator(m_translator);

        if( m_translator->load(newLanguage) && m_application != NULL)
        {
            m_language = language;
            m_application->installTranslator(m_translator);
            qDebug() << "language" << m_language << "has been installed";
            emit languageChanged();
        }
        else
        {
            qWarning() << tr("Cannot load the file") << newLanguage;
        }
    }
    else
    {
        qWarning() << tr("This language is already loaded");
    }
}
