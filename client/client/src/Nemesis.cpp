#include "ResourceLoader.hpp"
#include "SplashScreen.hpp"

int main(int argc, char ** argv)
{   
    // Checking args
    if(argc > 1) return FAILURE;
    std::cout << "\nRunning program : " << argv[0] << "\n" << std::endl;

    // Starting load of heavy resources
    // Launching thread
    ResourceLoader rLoader(DEBUG);
    rLoader.start();

    // Creating targets
    // TODO

    // Creating window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    WINDOW_NAME, sf::Style::Titlebar | sf::Style::Close);

    // Window framerate - Default : 120 fps
    window.setFramerateLimit(WINDOW_FPS);

    // Starting some videos while loading res
    SplashScreen splash(DEBUG);
    splash.start(&window);

    // Getting loaded resources
    // Wait if not finished
    while(!rLoader.getLoadState()) sf::sleep(sf::milliseconds(WAIT_TIME));
    ManagerGroup * managerGroup = rLoader.getManager();

    sf::Clock clock;
    while (window.isOpen())
    {
        double elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart().asMilliseconds();
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    return SUCCESS;
}