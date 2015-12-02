#include <SFML/Graphics.hpp>
#include <connection/FTPManager.h>

int main()
{
    FTPManager manager = FTPManager();
    manager.startFTP();
    //sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    manager.~FTPManager();
    return 0;
}