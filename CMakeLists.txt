cmake_minimum_required(VERSION 2.8)

project(rivin-zabih-queens)

set (CMAKE_CXX_STANDARD 11)

set(${PROJECT_NAME}_SOURCES
    constants.h
    lines.cpp
    lines.h
    )
add_executable(${PROJECT_NAME} "main.cpp"
    ${${PROJECT_NAME}_SOURCES}
    )
