cmake_minimum_required(VERSION 3.10)

project(Study)

set(GDK G:/Projects/Genesis/SGDK)

set(HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/res
        ${GDK}
        ${GDK}/inc
        ${GDK}/res)

set(SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    set(type debug)
ELSE()
    set(type clean release)
ENDIF()

set(SGDK_COMPILE_COMMAND
        ${GDK}/bin/make.exe
        -f ${GDK}/makelib.gen ${type})

set(PROJECT_COMPILE_COMMAND
        ${GDK}/bin/make.exe
        -f ${GDK}/makefile.gen ${type})

add_custom_target(game ALL ${SGDK_COMPILE_COMMAND}
        COMMAND ${PROJECT_COMPILE_COMMAND}
        DEPENDS ${HEADER_FILES}
        SOURCES ${SRC}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dummy ${SRC})
target_include_directories(dummy PUBLIC ${HEADER_FILES})