cmake_minimum_required(VERSION 3.5)

project(Tests)

set(TEST_ROOT
        ${CMAKE_CURRENT_SOURCE_DIR} )

set(TEST_HEADER_FILES
        ${TEST_ROOT})

set(TEST_SRC
        ${TEST_ROOT}/main.c
        ${TEST_ROOT}/mytests.c
        )

add_executable(unit_tests ${TEST_SRC})

enable_testing()

add_test(NAME unit_tests COMMAND ${TARGET_FILE}/unit_tests)