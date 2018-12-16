cmake_minimum_required(VERSION 2.8)

# Options. Turn off with 'cmake -Dmyvarname=OFF'.
option(test "Build all tests." ON) # Makes boolean 'test' available.

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME histogram_equalizer)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")

# for MSVC
if(MSVC)
  set(variables 
    CMAKE_CXX_FLAGS_DEBUG
    CMAKE_CXX_FLAGS_RELEASE
	CMAKE_CXX_FLAGS_RELWITHDEBINFO
	CMAKE_CXX_FLAGS_MINSIZEREL
  )
  foreach(variable ${variables})
	if(${variable} MATCHES "/MD")
	  string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
	endif()
  endforeach()
endif()

add_subdirectory(src)
add_subdirectory(unit-test)

set(COMMON_INCLUDES ${OpenCV_INCLUDE_DIRS})
