set(LIBRARY_NAME converter)
set(LIBRARY_HEADERS_DIR include)

set(LIBRARY_HEADERS include/converter.h
                    include/converterFactory.h
                    include/mix.h
        include/noise.h
                    include/mute.h)

set(LIBRARY_SOURCE  src/converterFactory.cpp
                    src/mix.cpp
        src/noise.cpp
                    src/mute.cpp
        )

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_HEADERS_DIR} ${CMAKE_SOURCE_DIR}/libs/WAV/include)
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LINK_LIBRARY} WAV)

set(TEST_LIBRARY_NAME converter_tests)
set(TEST_SOURCE test/converter_tests.cpp)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(${TEST_LIBRARY_NAME} ${TEST_SOURCE})
target_link_libraries(${TEST_LIBRARY_NAME} gtest_main ${LIBRARY_NAME})