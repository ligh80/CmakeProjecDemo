# google test
set(test_dir “test”)
include_directories(“${PROJECT_SOURCE_DIR}/${test_dir}”)
set(TEST_SOURCE_FILES ${CMAKE_CURRENT_LIST_DIR}/test.cc)

add_executable(runUnitTests ${TEST_SOURCE_FILES})
target_include_directories(runUnitTests PRIVATE “${PROJECT_SOURCE_DIR}/${test_dir}”)
target_link_libraries(runUnitTests gtest gtest_main)
# 包含项目中原来的库
target_link_libraries (runUnitTests ${EXTRA_LIBS})

# Discover and add test cases to the test runner
if(BUILD_TESTING)
add_test(NAME UnitTests COMMAND runUnitTests –gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/test_results.xml)
endif()
