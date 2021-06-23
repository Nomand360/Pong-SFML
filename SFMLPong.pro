TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
SOURCES += \
        Ball.cpp \
        Game.cpp \
        Player.cpp \
        Window.cpp \
        main.cpp

HEADERS += \
    Ball.h \
    Game.h \
    LIBS.h \
    Player.h \
    Window.h
