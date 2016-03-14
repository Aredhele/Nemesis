#include <stdlib.h>
#include "connector/MySQLConnector.hpp"
#include "clientConnector/ClientServer.hpp"

int main(int argc, char ** argv)
{
    //Connnect to the bdd
    //MySQLConnector *connector = new MySQLConnector();

    //BDD getter
    /*
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

    connector->disconnect();*/



    //Creating and starting server

    ClientServer serveur;

    if(serveur.start() != 0) {
        std::cout << "Erreur lors de la création du seveur" << std::endl;
        return -1;
    }

    return 0;
}