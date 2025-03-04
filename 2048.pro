QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/field.cpp \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/scoreswindow.cpp

HEADERS += \
    Headers/field.h \
    Headers/mainwindow.h \
    Headers/scoreswindow.h

FORMS += \
    UI/field.ui \
    UI/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    2048.ico

RESOURCES += \
    Sources/icon.qrc
