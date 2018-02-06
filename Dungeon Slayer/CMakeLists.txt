cmake_minimum_required(VERSION 2.8.12)
project(new64)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

#set(QT5_LIB_DIR C:/Qt/5.5/mingw510r0-seh-rev0/lib/cmake)
set (CMAKE_PREFIX_PATH C:/Qt/5.5/mingw510r0-seh-rev0)

find_package(Qt5Widgets REQUIRED )
find_package(Qt5Core REQUIRED )
find_package(Qt5Gui REQUIRED )

set(QT_BIN "${PROJECT_SOURCE_DIR}/qt-build")
include_directories(${QT_BIN})
add_custom_target(qtMakefile COMMAND make -C ${QT_BIN})

set(SOURCE_FILES
        main.cpp
        core/Leaf.h
        core/Leaf.cpp
        core/constants.h
        gui/Tile.h
        gui/Tile.cpp
        Nemico.cpp
        Nemico.h
        Arma.h
        Arma.cpp
        gui/Personaggio.h
        gui/Personaggio.cpp
        mainwindow.h
        mainwindow.cpp
        mainwindow.ui gui/Item.cpp gui/Item.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Gui Qt5::Core Qt5::Widgets)
