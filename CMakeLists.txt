project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RunChatTests TestChat.cpp)
target_link_libraries(RunChatTests gtest gtest_main)