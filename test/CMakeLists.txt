include(GoogleTest)

set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}.u.t test_hello.u.t.cpp test_world.u.t.cpp)
add_dependencies(${BINARY}.u.t ${BINARY}_world)
target_include_directories(${BINARY}.u.t PUBLIC ../include)
target_link_libraries(${BINARY}.u.t ${BINARY}_hello gtest_main gmock gtest pthread dl)

gtest_discover_tests(${BINARY}.u.t
    WORKING_DIRECTORY ${PROJECT_DIR}
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
)
