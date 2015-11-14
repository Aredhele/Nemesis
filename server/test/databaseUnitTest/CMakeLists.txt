include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDatabaseUnitTest
        querieUnitTest.cpp)

target_link_libraries(runDatabaseUnitTest gtest gtest_main)
target_link_libraries(runDatabaseUnitTest database)