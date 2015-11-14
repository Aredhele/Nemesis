#include <stdlib.h>
#include <iostream>

#include <database/ItemDB.hpp>
#include <database/Querie.hpp>

using namespace std;

int main(int argc, char ** argv)
{
    ItemDB * item = new ItemDB();
    item->message();

    Table table;

    Querie::select(&table, "test", "ing", NULL);
    
    return EXIT_FAILURE;
}