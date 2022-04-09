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
  include/list.hxx
  include/base_table.hxx
  include/arr_table.hxx
  include/stack.hxx
  include/polynomial.hxx
  include/monom.hxx
  include/interface.hxx
  include/chaining_hash_table.hxx
  include/postfix.hxx
  include/ordered_table.hxx
  include/list_table.hxx
  include/tree_table.hxx
  include/open_access_hash_table.hxx
)

set(Sources
  src/arr_table.cxx
  src/polynomial.cxx
  src/monom.cxx
  src/interface.cxx
  src/chaining_hash_table.cxx
  src/postfix.cxx
  src/ordered_table.cxx
  src/list_table.cxx
  src/base_table.cxx
  src/tree_table.cxx
  src/open_access_hash_table.cxx
)

add_library(${This} STATIC ${Sources} ${Headers})