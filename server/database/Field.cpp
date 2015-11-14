/**
 * \brief Field of table
 * \file Field.cpp
 * \author Aredhele
 * \version 0.1
 * \date 14/11/2015
 */

#include "database/Field.hpp"

/**
 * \brief Constructor.
 * \param field a field of a row
 */
Field::Field(std::string field) {
    m_fieldData = field;
}

/**
 * \brief Destructor.
 */
Field::~Field() {
    // None
}

/**
 * \brief Return the value of field
 * \return m_fieldData
 */
std::string Field::getFieldData() {
    return m_fieldData;
}