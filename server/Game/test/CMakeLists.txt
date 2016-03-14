# Project : Nemesis
# Version : 1
# Part    : Server tests
project(serverTest)

# Adding sub directories
# lib/gtest  - gtest files
# test       - Unit test files
add_subdirectory(lib/gtest)
add_subdirectory(databaseUnitTest)
add_subdirectory(connectorUnitTest)