unix:!android {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}

mytarget.path = /home/gael/Development/Qt_App/00_TranslationApp/TranslationApp/

export(INSTALLS)
