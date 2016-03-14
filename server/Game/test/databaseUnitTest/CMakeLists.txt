include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDatabaseUnitTest
        FieldUnitTest.cpp
        TableUnitTest.cpp)

target_link_libraries(runDatabaseUnitTest
        gtest
        gtest_main
        database)