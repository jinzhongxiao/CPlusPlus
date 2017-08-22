cmake_minimum_required(VERSION 2.6)

set(rootProject cpp-sdk-samples)
project(${rootProject})




# Boost package
# ----------------------------------------------------------------------------
# BOOST_ROOT  is needed by  BoostConfig.cmake configuration file to
# look for the Boost includes / libraries:
#         Boost_FOUND, Boost_INCLUDE_DIRS, Boost_LIBRARY_DIRS, Boost_LIBRARIES,Boost_VERSION

set( BOOST_COMPONENTS system filesystem date_time regex thread timer chrono serialization log log_setup program_options)

set( BOOST_MIN_VERSION "1.54.0" CACHE STRING "Minimum version of boost you would like to link against (e.g. C:/BOOST_1_55_0 is 1.55.0" )


find_package( Boost ${BOOST_MIN_VERSION} REQUIRED COMPONENTS ${BOOST_COMPONENTS} )

if( NOT Boost_FOUND )
    if( NOT DEFINED BOOST_ROOT )
        set( BOOST_ROOT "" CACHE PATH "Root directory for Boost." )
    endif( NOT DEFINED BOOST_ROOT )
    message( FATAL_ERROR "Failed to find Boost (or missing components). Double check that \"BOOST_ROOT\" is properly set")
endif( NOT Boost_FOUND )



add_subdirectory(option)
