//
// Created by Jehan on 04/01/2016.
//


#include "view/RenderEngine.hpp"

RenderEngine::RenderEngine() :
m_thread(&RenderEngine::graphicEngine,this),
m_backgroundTexture(),
m_backgroundSprite(),
m_log(sf::Vector2f(446,179)),
m_playButton(sf::Vector2f(104, 240), "../res/img/arrowLaunch.png",
             "../res/img/arrowLaunchPress.png",
             "../res/img/arrowLaunchOld.png"),
m_animatedButton(sf::Vector2f(109,245), "../res/img/animatedPlayButton.png"),
m_upButton(sf::Vector2f(615, 115), "../res/img/arrowUp.png",
           "../res/img/arrowUpPress.png"),
m_downButton(sf::Vector2f(615, 270), "../res/img/arrowDown.png",
           "../res/img/arrowDownPress.png"),
m_closeButton(sf::Vector2f(630, 10), "../res/img/close.png",
             "../res/img/closePress.png"),
m_progressBar(sf::Vector2f(0, 394), "../res/img/progressBar.png")
{
    m_animatedButton.init(false, 0.05, 87,87,36 );
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
                            "Paper Sword - Online : Updater",
                            sf::Style::None);

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
        m_animatedButton.update(elapsedTime);
        m_closeButton.update(elapsedTime);
        m_closeButton.handle(&e);



        if(m_upButton.isPress())
            m_log.cursorUp();

        if(m_downButton.isPress())
            m_log.cursorDown();

        if(m_closeButton.isPress()){
            window.close();
            setThreadState(false);
        }


        if(m_playButton.isPress()){
            system("cd ..\\..\\client\\bin && Client.exe &");
        }

        window.clear();
        window.draw(m_backgroundSprite);
        m_log.draw(&window);
        m_progressBar.draw(&window);
        m_upButton.draw(&window);
        m_downButton.draw(&window);

        if (m_animatedButton.isLoading())
            m_animatedButton.draw(&window);
        else
            m_playButton.draw(&window);

        m_closeButton.draw(&window);
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

ProgressBar* RenderEngine::getProgressBar(){
    return &m_progressBar;
}

AnimatableObject* RenderEngine::getAnimatableObject(){
    return &m_animatedButton;
}