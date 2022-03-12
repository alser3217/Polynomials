# CMake generated Testfile for 
# Source directory: K:/Labs/2Year/Polynomials/tests
# Build directory: K:/Labs/2Year/Polynomials/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(TESTS "K:/Labs/2Year/Polynomials/build/tests/Debug/TESTS.exe")
  set_tests_properties(TESTS PROPERTIES  _BACKTRACE_TRIPLES "K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;21;add_test;K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(TESTS "K:/Labs/2Year/Polynomials/build/tests/Release/TESTS.exe")
  set_tests_properties(TESTS PROPERTIES  _BACKTRACE_TRIPLES "K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;21;add_test;K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(TESTS "K:/Labs/2Year/Polynomials/build/tests/MinSizeRel/TESTS.exe")
  set_tests_properties(TESTS PROPERTIES  _BACKTRACE_TRIPLES "K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;21;add_test;K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(TESTS "K:/Labs/2Year/Polynomials/build/tests/RelWithDebInfo/TESTS.exe")
  set_tests_properties(TESTS PROPERTIES  _BACKTRACE_TRIPLES "K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;21;add_test;K:/Labs/2Year/Polynomials/tests/CMakeLists.txt;0;")
else()
  add_test(TESTS NOT_AVAILABLE)
endif()
