#include <stdlib.h>
#include "connector/MySQLConnector.hpp"

int main(int argc, char ** argv)
{
    MySQLConnector *connector = new MySQLConnector();

    connector->connect();
    connector->disconnect();

    std::vector < Table* > tablesName = connector->getTablesName();

    for (int i = 0; i < tablesName.size(); ++i) {
        std::cout << tablesName[i]->getTableName() << std::endl;
    }

    return EXIT_SUCCESS;
}