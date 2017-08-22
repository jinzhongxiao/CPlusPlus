CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(first)

add_executable(first first.cpp)

set( BOOST_COMPONENTS  program_options)

set( BOOST_MIN_VERSION "1.54.0" CACHE STRING "Minimum version of boost you would like to link against (e.g. C:/BOOST_1_55_0 is 1.55.0" )

find_package( Boost ${BOOST_MIN_VERSION} REQUIRED COMPONENTS ${BOOST_COMPONENTS} )

if( NOT Boost_FOUND )
    message( FATAL_ERROR "Failed to find Boost (or missing components). Double check that \"BOOST_ROOT\" is properly set")
endif( NOT Boost_FOUND )

target_link_libraries( first  ${Boost_LIBRARIES} )

