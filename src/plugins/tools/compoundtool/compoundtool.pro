# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/plugins/tools/compoundtool
# Target is a library:  

INSTALLS += target 
target.path = /plugins/

HEADERS += tweener.h \
           buttonspanel.h \
           configurator.h \
           tweenerpanel.h \
           # settings.h \
           tweenmanager.h \
           target.h

SOURCES += tweener.cpp \
           buttonspanel.cpp \
           configurator.cpp \
           tweenerpanel.cpp \
           # settings.cpp \
           tweenmanager.cpp \
           target.cpp

CONFIG += plugin warn_on
TEMPLATE = lib
TARGET = compoundtool

FRAMEWORK_DIR = "../../../framework"
include($$FRAMEWORK_DIR/framework.pri)
include(../tools_config.pri)

include(../../../../tupiglobal.pri)
