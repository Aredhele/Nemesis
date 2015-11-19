/**
 * \brief Unit test of class Field
 * \file FieldUnitTest.cpp
 * \author Aredhele
 * \version 0.1
 * \date 15/11/2015
 * \class FieldUnitTest
 */

// Header
#include "gtest/gtest.h"
#include "database/Field.hpp"

class FieldFixture : public ::testing::Test {

    protected:
        virtual void TearDown() {}
        virtual void SetUp() {}

    public:
        FieldFixture() : Test() {
            m_testField = new Field("test");
        }

        /**
         * Deleting properly pointer
         */
        virtual ~FieldFixture() {
            delete m_testField;
            m_testField = 0;
        }

        Field * m_testField;
};

/**
 * Test if the value of field is correct
 */
TEST_F(FieldFixture, fieldValueCheck) {
    EXPECT_EQ("test", m_testField->getFieldData());
}