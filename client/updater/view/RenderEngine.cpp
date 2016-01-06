//
// Created by Jehan on 04/01/2016.
//


#include "view/RenderEngine.hpp"

RenderEngine::RenderEngine() :
m_thread(&RenderEngine::graphicEngine,this),
m_backgroundTexture(),
m_backgroundSprite(),
m_log(sf::Vector2f(10,200), "../res/img/Log.png"),
m_playButton(sf::Vector2f(450, 200), "../res/img/arrowLaunch.png", "../res/img/arrowLaunchPress.png"),
m_upButton(sf::Vector2f(380, 200), "../res/img/arrowUp.png",
           "../res/img/arrowUpPress.png"),
m_downButton(sf::Vector2f(380, 350), "../res/img/arrowDown.png",
           "../res/img/arrowDownPress.png")
{
    m_running = false;
    m_backgroundTexture.loadFromFile("../res/img/background.png");
    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_backgroundSprite.setPosition(0, 0);
    m_playButton.enable(false);
}

RenderEngine::~RenderEngine() {

}

void RenderEngine::graphicEngine(){

    sf::RenderWindow window(sf::VideoMode(650, 400),
           "Knights of Pen and Paper : Updater",
           sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    while(window.isOpen()){

        if(!m_running) {
            window.close();
            continue;
        }

        double elapsedTime = clock.getElapsedTime().asSeconds();
        clock.restart().asMilliseconds();

        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed){
                window.close();
                setThreadState(false);
            }
        }

        // Updating game logic
        m_upButton.update(elapsedTime);
        m_upButton.handle(&e);
        m_downButton.update(elapsedTime);
        m_downButton.handle(&e);
        m_playButton.update(elapsedTime);
        m_playButton.handle(&e);


        if(m_upButton.isPress())
            m_log.cursorUp();

        if(m_downButton.isPress())
            m_log.cursorDown();

        if(m_playButton.isPress()){
            system("cd ..\\..\\client\\bin && Client.exe &");
        }

        window.clear();
        window.draw(m_backgroundSprite);
        m_log.draw(&window);
        m_upButton.draw(&window);
        m_downButton.draw(&window);
        m_playButton.draw(&window);
        window.display();
    }
    m_running = false;
}

void RenderEngine::startEngine() {
    m_running = true;
    m_thread.launch();
}

void RenderEngine::setThreadState(bool state) {
    m_running = state;
}
bool RenderEngine::getThreadState() {
    return m_running;
}

Log* RenderEngine::getLog(){
    return &m_log;
}

Button* RenderEngine::getButton(){
    return &m_playButton;
}