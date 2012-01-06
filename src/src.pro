TEMPLATE = app
TARGET = xmppplugin

CONFIG += qt link_pkgconfig warn_on \
          qdeclarative-boostable \
          meegotouch 
#CONFIG += debug

CONFIG(debug){
        DEFINES += DEBUG
}

QT += xml declarative
QT -= thread

PKGCONFIG += NAccountPlugin meegotouch

QMAKE_CXXFLAGS += -fPIC -fvisibility=hidden -fvisibility-inlines-hidden
QMAKE_LFLAGS += -pie -rdynamic

HEADERS = xmppplugin.h \
          xmppaccountadd.h \
          xmppaccountedit.h

SOURCES = xmppplugin.cpp \
          xmppaccountadd.cpp \
          xmppaccountedit.cpp 

RESOURCES += qml.qrc
OTHER_FILES += resources/qml/xmpp-settings.qml

target.path = $$system(pkg-config --variable=providerplugindir AccountPlugin)/bin
INSTALLS += target

stylesheets.path = /usr/share/themes/base/meegotouch/xmppplugin/style
stylesheets.files =  $${_PRO_FILE_PWD_}/xmppplugin.css
INSTALLS += stylesheets
