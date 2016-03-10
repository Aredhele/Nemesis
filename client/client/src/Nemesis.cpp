// TODO : Gérer cette histoire d'option
// OK   : Bouton clic
// TODO : Gérer la propriété hidden des objets

#include "ResourceLoader.hpp"
#include "SplashScreen.hpp"
#include "LoginMenu.hpp"
#include "Lobby.hpp"
#include "WarmUp.hpp"
#include "Game.hpp"

int main(int argc, char ** argv)
{   
    // Checking args
    if(argc > 1) return FAILURE;
    std::cout << "\nRunning program : " << argv[0] << "\n" << std::endl;

    // Starting load of heavy resources
    // Launching thread
    ResourceLoader rLoader(DEBUG);
    rLoader.start();

    // Creating window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
    WINDOW_NAME, sf::Style::None);

    // Window framerate - Default : 120 fps
    window.setFramerateLimit(WINDOW_FPS);

    // Starting some videos while loading res
    SplashScreen splash(DEBUG);
    //splash.start(&window);

    // Getting loaded resources
    // Wait if not finished
    while(!rLoader.getLoadState()) sf::sleep(sf::milliseconds(WAIT_TIME));
    ManagerGroup * managerGroup = rLoader.getManager();

    // Creating menu
    LoginMenu loginMenu(DEBUG, managerGroup);

    //Creating lobby
    Lobby lobby(DEBUG, managerGroup);

    //Creating warmUp
    WarmUp warmUp(DEBUG, managerGroup);

    //Creating Game
    Game game(DEBUG, managerGroup);

    // Setting main target
    managerGroup->ptr_targetManager->isOnGame();



    sf::Clock clock;
    while (window.isOpen())
    {   
        // Exiting program
        if(!managerGroup->ptr_targetManager->isExit()) {
            managerGroup->ptr_musicManager->stopPlaylist();
            window.close();
            continue;
        }

        double elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart().asMilliseconds();
        window.clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Updating game logic
        loginMenu.update(&window, &event, elapsedTime);
        lobby.update(&window, &event, elapsedTime);
        warmUp.update(&window, &event, elapsedTime);
        game.update(&window, &event, elapsedTime);
        managerGroup->ptr_musicManager->update();

        window.display();
    }

    return SUCCESS;
}