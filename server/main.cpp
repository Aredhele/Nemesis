#include <stdlib.h>
#include <iostream>

#include <database/ItemDB.hpp>

using namespace std;

int main(int argc, char ** argv)
{
    cout << "Nemesis" << endl;

    ItemDB * item = new ItemDB();
    item->message();

    return EXIT_FAILURE;
}

