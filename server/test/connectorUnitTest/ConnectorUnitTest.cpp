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
 * Test if the connection is ok
 */
TEST_F(ConnectorFixture, connectorConnectionCheck) {
    EXPECT_EQ(0, m_testConnector->connect());
    // Disconnection
    m_testConnector->disconnect();

    // Changing id
    m_testConnector->setId("test");
    EXPECT_NE(0, m_testConnector->connect());
}



