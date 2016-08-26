cmake_minimum_required(VERSION 3.5.1)
project(Tutorial)
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

set (PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set (PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/inc)

option (USE_MYMATH
        "Use my math lib" ON)
message ("USE_MYMATH = ${USE_MYMATH}}")

if (USE_MYMATH)
  include_directories("${CMAKE_SOURCE_DIR}/MathFunctions")
  add_subdirectory(MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MyMath)
endif (USE_MYMATH)

include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

message ("HAVE_LOG = ${HAVE_LOG} HAVE_EXP = ${HAVE_EXP}")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

add_executable(tutorial ${PROJECT_SOURCE_DIR}/tutorial.cxx)
target_link_libraries(tutorial ${EXTRA_LIBS})

include(CTest)
add_test (TutorialRuns tutorial 25)
add_test (TutorialComp25 tutorial 25)
set_tests_properties (TutorialComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
