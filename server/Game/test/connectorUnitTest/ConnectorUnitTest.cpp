/**
 * \brief Unit test of class MySQLConnector
 * \file FieldUnitTest.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class FieldUnitTest
 */

// Header
#include "gtest/gtest.h"
#include "database/Table.hpp"
#include "connector/MySQLConnector.hpp"

class ConnectorFixture : public ::testing::Test {

protected:
    virtual void TearDown() {}
    virtual void SetUp() {}

public:
    ConnectorFixture() : Test() {
        m_testConnector = new MySQLConnector();
    }

    /**
     * Deleting properly pointer
     */
    virtual ~ConnectorFixture() {
        delete m_testConnector;
        m_testConnector = 0;
    }

    MySQLConnector * m_testConnector;
};

/**
 * Test of tables name
 */
TEST_F(ConnectorFixture, connectorTableNameCheck) {
    m_testConnector->connect();
    const char * names[15] =
    {"class", "classrole", "displayable",
    "displayabletype", "item", "itemlocation",
    "itemscarcity", "itemtype", "monster", "npc", "npcaction", "skill",
    "skilltarget", "statistic", "user"};

    // Declaring our vector of table
    std::vector < Table* > tablesName = m_testConnector->getTablesName();

    for(int i = 0; i < 15; ++i) {
        EXPECT_EQ(names[i], tablesName[i]->getTableName());
    }
    m_testConnector->disconnect();
}

TEST_F(ConnectorFixture, connectorColumnsNameCheck) {
    m_testConnector->connect();
    const char * names[6] = {"classId", "classRole", "classAttribut",
                             "classSkill", "classDescription", "classSpriteID"};

    // Getting table
    std::vector < Table* > tablesName = m_testConnector->getTablesName();

    // Getting columns of table 0
    m_testConnector->getColumnsFromTable(tablesName[0]);

    // Checking values
    for(int i = 0; i < tablesName[0]->getColumnsName()->size(); i++) {
        EXPECT_EQ(names[i], (*tablesName[0]->getColumnsName())[i]);
    }
    m_testConnector->disconnect();
}

