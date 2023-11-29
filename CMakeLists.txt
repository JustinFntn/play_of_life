cmake_minimum_required(VERSION 3.10)

project(TP4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "~/Qt/6.6.0/macos/lib/cmake/")
set(Qt6_DIR "~/Qt/6.6.0/macos/lib/cmake/Qt6")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(tp4
    Plateau.cpp
    Cell.cpp
    main.cpp
    mainwindow.cpp
    GraphicScene.cpp
)

target_link_libraries(tp4 PRIVATE Qt6::Widgets)
target_link_libraries(tp4 PRIVATE Qt6::Core)