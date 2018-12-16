cmake_minimum_required(VERSION 2.8)

#project(${PROJECT_NAME})

# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'
  add_subdirectory(./gtest-1.6.0)
	
  enable_testing()
  find_package( OpenCV REQUIRED core imgproc highgui)
  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  include_directories(${PROJECT_SOURCE_DIR}/src)
 include_directories(${COMMON_INCLUDES})
  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests unit-test.cpp)

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  
  target_link_libraries(runUnitTests ${OpenCV_LIBS})

endif()
