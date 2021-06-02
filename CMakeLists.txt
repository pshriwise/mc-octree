cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(mcoctree CXX)

add_library(mcoct octree.cpp)

enable_testing()

add_executable(test_tree test_tree.cpp)
target_link_libraries(test_tree mcoct)

add_test(NAME tree_test COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_tree)


