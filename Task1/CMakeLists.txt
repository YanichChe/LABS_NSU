cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME lab1)
set(SOURCE src/main.cpp)
set(LIBRARY_DIR libs)
set(LIBRARY big_int comparison)

project(${PROJECT_NAME} CXX)

add_executable(${PROJECT_NAME} ${SOURCE})

foreach(LIBRARY ${LIBRARY})
    add_subdirectory("${LIBRARY_DIR}/${LIBRARY}")
    message(STATUS "Add subdirectory ${LIBRARY_DIR}/${LIBRARY}")
endforeach(LIBRARY)

target_link_libraries(${PROJECT_NAME} ${LIBRARY})