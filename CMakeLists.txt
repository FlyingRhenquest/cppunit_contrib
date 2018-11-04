# Set up Cmake (Min version, disable in-source-build et al)
cmake_minimum_required(VERSION 3.13)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Set up project
project(cppunit_contrib CXX)
set(CMAKE_CXX_STANDARD 14)
include_directories(BEFORE ${CMAKE_SOURCE_DIR}/include)
find_package(PkgConfig)
pkg_search_module(cppunit REQUIRED cppunit)

# Set up test executables
add_executable(basic_test src/test_runner_basic.cpp test/basic_test.cpp)
target_link_libraries(basic_test ${cppunit_LIBRARIES})

add_executable(exception_test src/test_runner_basic.cpp test/exception_test.cpp)
target_link_libraries(exception_test ${cppunit_LIBRARIES})

add_executable(segv_test src/test_runner_basic.cpp test/segv_test.cpp)
target_link_libraries(segv_test ${cppunit_LIBRARIES})

# Set up tests. These will run when you run ctest.
# use ctest --verbose to see the reports from the listener.
enable_testing()
add_test(NAME basic_test COMMAND basic_test)
add_test(NAME exception_test COMMAND exception_test)
add_test(NAME segv_test COMMAND segv_test)

# Set up installer
include(GNUInstallDirs)
install(FILES ${CMAKE_SOURCE_DIR}/include/fr/cppunit DESTINATION include/fr/)
install(FILES ${CMAKE_SOURCE_DIR}/include/fr/cppunit_contrib/listener DESTINATION include/fr/cppunit_contrib/)
install(FILES ${CMAKE_SOURCE_DIR}/src/test_runner_basic.cpp DESTINATION ${CMAKE_INSTALL_DOCDIR})
