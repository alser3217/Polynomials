cmake_minimum_required(VERSION 3.15)

set (This TESTS)

set (Sources
  test_arr_table.cxx
  test_list_table.cxx
  test_ordered_table.cxx
  test_chaining_hash_table.cxx
  test_list.cxx
  test_monom.cxx
  test_open_access_hash_table.cxx
  test_polynomial.cxx
  test_tpostfix.cxx
  test_tstack.cxx
)

include_directories("../include")
include_directories("../src")


add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
  gtest_main
  Polynomials
)

add_test(
  NAME ${This}
  COMMAND ${This}
)