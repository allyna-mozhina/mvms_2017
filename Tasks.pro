QT += core
QT -= gui

CONFIG += c++11

TARGET = Tasks
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    task1.cpp

HEADERS += \
    task1.h \
    commun_task.h

OPENCV3_INSTALL_PREFIX = C:/Develop/Cpp/Libs/opencv-3.1
win32-msvc2015 {
    OPENCV3_INCLUDE_PATH = $${OPENCV3_INSTALL_PREFIX}/build/include
    OPENCV3_LIB_PATH = -L"$${OPENCV3_INSTALL_PREFIX}/build/x64/vc14/lib" \
        -L"$${OPENCV3_INSTALL_PREFIX}/build/x64/vc14/bin"
    OPENCV3_LIB_SUFF = 310
    CONFIG(debug, debug | release): OPENCV3_LIB_SUFF = $${OPENCV3_LIB_SUFF}d
    OPENCV3_LIBS = -lopencv_world$${OPENCV3_LIB_SUFF}
}
INCLUDEPATH += \
    "$${VSYNS_INCLUDE_PATH}" \
    "$${OPENCV3_INCLUDE_PATH}"

LIBS += \
    $${OPENCV3_LIB_PATH} \
    $${OPENCV3_LIBS}
