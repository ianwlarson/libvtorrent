cmake_minimum_required(VERSION 3.0)

enable_testing()

IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
	MESSAGE("Debug build.")
ELSE()
	MESSAGE("Release build.")
ENDIF()

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG  "${CMAKE_EXE_LINKER_FLAGS_DEBUG} ${GCC_COVERAGE_LINK_FLAGS}")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -Wall ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os -Wall")

add_library(vtorrent SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/src/v_hexstring.c)

add_executable(test_main ${CMAKE_CURRENT_SOURCE_DIR}/test/main.c)
add_executable(v_test_hexstring ${CMAKE_CURRENT_SOURCE_DIR}/test/v_test_hexstring.c)

find_package(cmocka REQUIRED)

target_link_libraries(test_main cmocka)
target_link_libraries(v_test_hexstring cmocka vtorrent)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_test(TEST_MAIN test_main
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/test_main)

add_test(TEST_HEXSTRING v_test_hexstring
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/bin/v_test_hexstring)

install(TARGETS test_main RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
install(TARGETS v_test_hexstring RUNTIME DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin)
