QT += opengl core gui svg xml network

unix {
    !include(../../tupiglobal.pri) {
        error("Please configure first")
    }
}

win32 {
    include(../../win.pri)
}

INSTALLS += target
target.path = /lib/

contains("DEFINES", "ADD_HEADERS") {
    INSTALLS += headers
    headers.target = .
    headers.commands = cp *.h $(INSTALL_ROOT)/include/tupinet
    headers.path = /include/tupinet/
}

macx {
    CONFIG += plugin warn_on
}

HEADERS += tupnetprojectmanagerparams.h \
           tupnetprojectmanagerhandler.h \
           tupnetsocket.h \
           tupconnectpackage.h \
           tuplistpackage.h \
           tupopenpackage.h \
           tupsavepackage.h \
           tupnewprojectpackage.h \
           tupnetfilemanager.h \
           tupchat.h \
           tupconnectdialog.h \
           tupprojectparser.h \
           tuplistprojectspackage.h \
           tupprojectlistparser.h \
           tuplistprojectdialog.h \
           tupnotificationparser.h \
           tupackparser.h \
           tupimportprojectpackage.h \
           tupchatpackage.h \
           tupnotice.h \
           # tupnoticepackage.h \
           tupcommunicationparser.h \
           tupimageexportpackage.h \
           tupvideoexportpackage.h \
           tupstoryboardupdatepackage.h \
           tupstoryboardexportpackage.h \
           tupstoryboardparser.h

SOURCES += tupnetprojectmanagerparams.cpp \
           tupnetprojectmanagerhandler.cpp \
           tupnetsocket.cpp \
           tupconnectpackage.cpp \
           tuplistpackage.cpp \
           tupopenpackage.cpp \
           tupsavepackage.cpp \
           tupnewprojectpackage.cpp \
           tupnetfilemanager.cpp \
           tupchat.cpp \
           tupconnectdialog.cpp \
           tupprojectparser.cpp \
           tuplistprojectspackage.cpp \
           tupprojectlistparser.cpp \
           tuplistprojectdialog.cpp \
           tupnotificationparser.cpp \
           tupackparser.cpp \
           tupimportprojectpackage.cpp \
           tupchatpackage.cpp \
           tupnotice.cpp \
           # tupnoticepackage.cpp \
           tupcommunicationparser.cpp \
           tupimageexportpackage.cpp \
           tupvideoexportpackage.cpp \
           tupstoryboardupdatepackage.cpp \
           tupstoryboardexportpackage.cpp \
           tupstoryboardparser.cpp

*:!macx{
    CONFIG += dll warn_on
}

TEMPLATE = lib
TARGET = tupinet 

include(net_config.pri)

FRAMEWORK_DIR = "../framework"
include($$FRAMEWORK_DIR/framework.pri)

