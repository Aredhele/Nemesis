#include <stdlib.h>
#include "connector/MySQLConnector.hpp"

int main(int argc, char ** argv)
{
    MySQLConnector *connector = new MySQLConnector();
    connector->connect();

    std::vector < Table* > tablesName = connector->getTablesName();

    for(int i = 0; i < tablesName.size(); i++) {
        connector->getColumnsFromTable(tablesName[i]);
        connector->getFieldFromTable(tablesName[i]);
    }

    for(int i = 0; i < tablesName.size(); i++) {
        std::cout << "TABLE : " << tablesName[i]->getTableName() << std::endl;
        tablesName[i]->displayColumns();
        tablesName[i]->displayFields();
        std::cout << std::endl;
    }

    connector->disconnect();
    return EXIT_SUCCESS;
}