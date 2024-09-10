cmake_minimum_required(VERSION 3.30)

project(custom-lib LANGUAGES C)

set(TARGET_GROUP production CACHE STRING "Group to build")

####################################################################################
# Set Variables:
####################################################################################
set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(SRC ${ROOT}/src)
set(EXAMPLES ${ROOT}/examples)
set(INCLUDE ${ROOT}/include)
set(TESTS ${ROOT}/tests)

file(GLOB MY_SOURCE_FILES ${SRC}/*.c)
file(GLOB MY_HEADER_FILES ${INCLUDE}/*.h)
file(GLOB MY_TEST_FILES ${TESTS}/*.c)

set(VECTOR_NAME "vector")

####################################################################################
# Create Library:
####################################################################################
add_library(${PROJECT_NAME} STATIC ${MY_SOURCE_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})

####################################################################################
# Create Example Executables:
####################################################################################
add_executable(${VECTOR_NAME} ${EXAMPLES}/${VECTOR_NAME}.c)
target_link_libraries(${VECTOR_NAME} ${PROJECT_NAME})

if(TARGET_GROUP STREQUAL test)
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

    ####################################################################################
    # Create Tests:
    ####################################################################################
    include(CTest)

    add_executable(${VECTOR_NAME}_test ${TESTS}/${VECTOR_NAME}.c)
    target_link_libraries(${VECTOR_NAME}_test ${PROJECT_NAME} unity)
    add_test(${VECTOR_NAME}_test ${VECTOR_NAME}_test)
endif()

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${MY_HEADER_FILES} DESTINATION include)

# ## Target installation
# install(TARGETS   ${PROJECT_NAME}
#     EXPORT        ${PROJECT_NAME}Targets
#     ARCHIVE       DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     LIBRARY       DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
#     COMPONENT     library
# )

# ## Target's cmake files: targets export
# install(EXPORT  ${PROJECT_NAME}Targets
#     NAMESPACE   ${PROJECT_NAME}::
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
# )

# ## Target's cmake files: config and version config for find_package()
# install(FILES   ${PROJECT_NAME}Config.cmake
#                 ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
#     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
# )