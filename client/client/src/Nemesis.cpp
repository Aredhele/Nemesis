#include "VideoPlayer.hpp"
#include "ResourceLoader.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Nemesis", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(120);

    MusicManager musicManager(DEBUG, true);
    musicManager.getPlaylist("plist")->start();

    VideoPlayer videoPlayer(DEBUG);
    videoPlayer.init(1024, 768, 40, 170, "../res/animation/splash/splash_0/");
    videoPlayer.setVideoState(videoState::PLAY);

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

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::P)
                    musicManager.pausePlaylist();

                if (event.key.code == sf::Keyboard::A)
                    musicManager.playPlaylist();

                if (event.key.code == sf::Keyboard::Q)
                    musicManager.stopPlaylist();
            }
        }

        videoPlayer.draw(&window, elapsedTime);

        window.display();
        musicManager.update();
    }

    return 0;
}