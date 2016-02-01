#include <stdlib.h>
#include "connector/MySQLConnector.hpp"
#include "clientConnector/ClientServer.hpp"

int main(int argc, char ** argv)
{
    MySQLConnector *connector = new MySQLConnector();
    ConsoleDisplayer displayer;
    Configuration configuration(&displayer);

    displayer.displayStartMessage();

    //Obtention of server configuration
    displayer.displayMessage("info", "Parcours du fichier de configuration");
    if (configuration.readConfiguration(CONF_PATH_CONFIG) != 0) {
        if (configuration.readConfiguration(CONF_PATH_CONFIG_MVS) != 0) {
            displayer.displayMessage("erro", "Echec du chargement de la configuration");
            displayer.displayMessage("warn", "Server OFF ...");
            return EXIT_FAILURE;
        }
    }

    //Config display
    configuration.displayConfiguration();

    //Creating and starting server

    ClientServer serveur(&displayer, &configuration);

    displayer.displayMessage("info", "Démarrage du serveur ...");
    if(serveur.start() != 0) {
        displayer.displayMessage("erro", "Impossible de démarrer le serveur");
        displayer.displayMessage("warn", "Server OFF ...");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;


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
    return EXIT_SUCCESS;
}