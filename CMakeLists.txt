cmake_minimum_required(VERSION 3.30)

project(custom-lib)

####################################################################################
# Set Variables:
####################################################################################
set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/graph)
set(SRC ${ROOT}/src)
set(INCLUDE ${ROOT}/include)
set(TESTS ${ROOT}/tests)

file(GLOB MY_SOURCE_FILES ${SRC}/*.c)
file(GLOB MY_HEADER_FILES ${INCLUDE}/*.h)
file(GLOB MY_TEST_FILES ${TESTS}/*.c)

####################################################################################
# Install Test Framework:
####################################################################################
include(FetchContent)
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        860062d51b2e8a75d150337b63ca2a472840d13c # v2.6.0
)
if (WIN32)
    add_definitions(-DUNITY_SUPPORT_64)
endif (WIN32)
FetchContent_MakeAvailable(unity)