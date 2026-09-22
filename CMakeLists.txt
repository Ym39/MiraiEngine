cmake_minimum_required(VERSION 3.20)
project(MiraiEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MiraiEngine
    src/main.cpp
    src/Application.cpp
    src/Application.h
)
target_compile_definitions(MiraiEngine PRIVATE UNICODE _UNICODE)
set_target_properties(MiraiEngine PROPERTIES WIN32_EXECUTABLE $<CONFIG:Debug>)
