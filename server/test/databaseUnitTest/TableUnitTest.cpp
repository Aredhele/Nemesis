/**
 * \brief Unit test of class Table
 * \file TableUnitTest.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class TableUnitTest
 */

// Header
#include <vector>
#include "gtest/gtest.h"
#include "database/Table.hpp"

class TableFixture : public ::testing::Test {

    protected:
        virtual void TearDown() {}
        virtual void SetUp() {}

    public:
        TableFixture() : Test() {
            m_testTable = new Table("TABLE");
            m_testTableC = new Table("TABLE", "id", "name", "level", NULL);
        }

        /**
        * Deleting properly pointer
        */
        virtual ~TableFixture() {
            delete m_testTable;
            delete m_testTableC;
            m_testTable = 0;
            m_testTableC = 0;
        }

        Table * m_testTable;
        Table * m_testTableC;
};

/**
 * Test if the value of field is correct
 */
TEST_F(TableFixture, tableNameCheck) {
    EXPECT_EQ("TABLE", m_testTable->getTableName());
}

/**
 * Test the second constructor
 */
TEST_F(TableFixture, tableConstructorCheck) {
    const char * names[3] = {"id", "name", "level"};

    // Checking columns name
    for(int i = 0; i < 3; ++i) {
        EXPECT_EQ(names[i], (*m_testTableC->getColumnsName())[i]);
    }
}

/**
 * Test the name of columns
 */
TEST_F(TableFixture, tableColumnsNameCheck) {
    const char * names[5] = {"id", "name", "level", "sprite", "type"};

    // Pushing columns name
    for (int i = 0; i < 5; ++i) {
        m_testTable->getColumnsName()->push_back(names[i]);
    }

    // Checking columns name
    for(int i = 0; i < 5; ++i) {
        EXPECT_EQ(names[i], (*m_testTable->getColumnsName())[i]);
    }
}

/**
 * Test the data of the table
 */
TEST_F(TableFixture, tableDataCheck) {
    const char * tdata[5] = {"1", "Kirito", "200", "5", "player"};

    // Pushing row
    m_testTable->getFieldArray()->push_back(std::vector < Field * > ());

    // Pushing data
    for (int i = 0; i < 5; ++i) {
        (*m_testTable->getFieldArray())[0].push_back(new Field(tdata[i]));
    }

    // Checking table data
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(tdata[i], (*m_testTable->getFieldArray())[0][i]->getFieldData());
    }

    // Setting value to 2
    (*m_testTable->getFieldArray())[0][0]->setFieldData("2");

    // "1" != "2"
    EXPECT_NE(tdata[0], (*m_testTable->getFieldArray())[0][0]->getFieldData());
}