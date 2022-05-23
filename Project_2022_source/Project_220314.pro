QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutfunction.cpp \
    backgroundcolfunction.cpp \
    btnclicked.cpp \
    buttoncolfunction.cpp \
    cancelbtn.cpp \
    editcolfunction.cpp \
    enfunction.cpp \
    exitfunction.cpp \
    main.cpp \
    mainclass.cpp \
    menucolfunction.cpp \
    radiobtnfunction.cpp \
    resizeevent.cpp \
    rusfunction.cpp \
    settingfunction.cpp \
    typetextbtnfunction.cpp

HEADERS += \
    mainclass.h

FORMS +=

RC_ICONS = icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
