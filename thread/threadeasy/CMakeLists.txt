cmake_minimum_required(VERSION 2.8)

project(thread1)
find_package(Boost REQUIRED COMPONENTS thread filesystem system signals)


add_executable(thread1 thread1.cpp)
target_link_libraries(thread1 ${Boost_LIBRARIES})
target_compile_features(thread1 PRIVATE cxx_range_for)
message("Your C++ compiler supports these C++ features:")
foreach(i ${CMAKE_CXX_COMPILE_FEATURES})
  message("${i}")
endforeach()