#include <stdlib.h>
#include "connector/MySQLConnector.hpp"

int main(int argc, char ** argv)
{
    MySQLConnector *connector = new MySQLConnector();

    connector->connect();
    connector->disconnect();

    return EXIT_SUCCESS;
}