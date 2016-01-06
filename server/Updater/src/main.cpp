#include <stdlib.h>
#include <cstdlib> 

#include "SFMLServer.hpp"

int main(int argc, char ** argv) {

	Parser * ptr_parser;
    SFMLServer * ptr_server;
    ConsoleDisplayer * ptr_displayer;
    Configuration * ptr_configuration;

    ptr_displayer = new ConsoleDisplayer();
    ptr_displayer->displayStartMessage();

    if(argc > 1) {
        ptr_displayer->displaySimple("Info", "Server started with option : ");
        std::cout << argv[1] << std::endl;
        ptr_parser = new Parser(argv[1], ptr_displayer);
    } else {
        ptr_parser = new Parser(ptr_displayer);
    }

    if((ptr_configuration = ptr_parser->parse()) == nullptr) {
        ptr_displayer->displayMessage("Fail", "Parser Error ...");
        return EXIT_FAILURE;
    }

    ptr_configuration->displayConfig();
    std::cout << std::endl;

    ptr_server = new SFMLServer(ptr_displayer, ptr_configuration);

    if(ptr_server->start() != 0) {
        ptr_displayer->displayMessage("Fail", "Could'nt start server .. ");
        return EXIT_FAILURE;
    }

    delete ptr_parser;
    delete ptr_server;
    delete ptr_displayer;
    delete ptr_configuration;

    ptr_parser = nullptr;
    ptr_server = nullptr;
    ptr_displayer = nullptr;
    ptr_configuration = nullptr;

    return EXIT_SUCCESS;
}