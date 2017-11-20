QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES = src/main.cpp ../sqlitecpp/sqlite3.c

DEPENDPATH +=
INCLUDEPATH += ../sqlitecpp
LIBS += -L../sqlitecpp -lSQLiteCpp
