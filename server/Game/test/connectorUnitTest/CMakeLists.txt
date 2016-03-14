include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runConnectorUnitTest
        ConnectorUnitTest.cpp)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/connector/lib)

target_link_libraries(runConnectorUnitTest
        gtest
        gtest_main
        connector
        wsock32
        mysqlclient
        database)