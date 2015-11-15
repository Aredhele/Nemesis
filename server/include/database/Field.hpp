/**
 * \brief Field of table
 * \file Field.hpp
 * \author Aredhele
 * \version 0.1
 * \date 14/11/2015
 * \class Field
 */

#ifndef DEF_SERVER_FIELD_HPP
#define DEF_SERVER_FIELD_HPP

// Header
#include <string>

class Field
{
    private:
        // Member
        std::string m_fieldData;

    public:
        // Constructor
        Field(std::string field);

        // Destructor
        ~Field();

        // Getter
        std::string getFieldData();

        // Setter
        void setFieldData(std::string data);
};

#endif // DEF_SERVER_FIELD_HPP
