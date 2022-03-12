cmake_minimum_required(VERSION 3.0.0)

set (This Polynomials)
project (${This} CXX)

set(CMAKE_C_STANDART 99)
set(CMAKE_CXX_STANDART 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(tests)
add_subdirectory(sample)

include_directories("include")
include_directories("src")

set (Headers
  include/base_table.hxx
  include/arr_table.hxx
  include/stack.hxx
  include/polynomial.hxx
  include/monom.hxx
  include/list.hxx
  include/interface.hxx
  include/hash_table.hxx
  include/postfix.hxx
  include/ordered_table.hxx
  include/list_table.hxx
)

set(Sources
  src/arr_table.cxx
  src/polynomial.cxx
  src/monom.cxx
  src/interface.cxx
  src/hash_table.cxx
  src/postfix.cxx
  src/ordered_table.cxx
  src/list_table.cxx
  src/base_table.cxx
)

add_library(${This} STATIC ${Sources} ${Headers})