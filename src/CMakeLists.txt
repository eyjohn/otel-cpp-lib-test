set(BINARY ${CMAKE_PROJECT_NAME})

add_library(${BINARY}_hello SHARED hello.cpp)
target_include_directories(${BINARY}_hello PUBLIC ../include)
set_target_properties(${BINARY}_hello PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "../include/hello.h")

add_library(${BINARY}_world SHARED world.cpp)
target_include_directories(${BINARY}_world PUBLIC ../include)
set_target_properties(${BINARY}_world PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "../include/world.h")

install(TARGETS ${BINARY}_hello ${BINARY}_world
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME})