/**
 * \brief Main file
 * \file main.cpp
 * \author Aredhele
 * \version 0.1
 * \date 19/11/2015
 */

// Header
#include <stdlib.h>

#include "Parser/Parser.hpp"

int main(int argc, const char ** argv) {

    Parser * parser;
    Configuration * configuration;
    ConsoleDisplayer * displayer = new ConsoleDisplayer();

    displayer->displayStartMessage();

    if(argc > 1) {
        displayer->displaySimple("Server started with option : ");
        std::cout << argv[1] << std::endl;
        parser = new Parser(argv[1], displayer);
    } else {
        parser = new Parser(displayer);
    }

    if((configuration = parser->parse()) == nullptr) {
        displayer->displayWarn("Parser Error ...");
        return EXIT_FAILURE;
    }

    configuration->displayConfig();

    return EXIT_SUCCESS;
}