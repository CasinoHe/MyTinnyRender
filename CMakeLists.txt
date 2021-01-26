cmake_minimum_required(VERSION 3.19)

project(MyTinnyRender LANGUAGES CXX)

set(SRC_ROOT ${CMAKE_SOURCE_DIR})

set(SRC_FILES
  ${SRC_ROOT}/main.cpp
  ${SRC_ROOT}/tga/tgaimage.cpp
)

include_directories(${SRC_ROOT})

add_executable(${PROJECT_NAME} ${SRC_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)