//
// Created by Jehan on 04/01/2016.
//

#ifndef DEF_RENDER_ENGINE_HPP
#define DEF_RENDER_ENGINE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Log.hpp"
#include "Button.hpp"
#include "ProgressBar.hpp"
#include "AnimatableObject.hpp"


class RenderEngine
{
    private:
        bool m_running;
        sf::Thread m_thread;
        sf::Texture m_backgroundTexture;
        sf::Sprite m_backgroundSprite;
        Log m_log;
        Button m_playButton;
        AnimatableObject m_animatedButton;
        Button m_upButton;
        Button m_downButton;
        Button m_closeButton;
        ProgressBar m_progressBar;


        void graphicEngine();


    public:
        RenderEngine();

        ~RenderEngine();

        void startEngine();


        // Setters
        void setThreadState(bool state);

        //Getters
        bool getThreadState();
        Log* getLog();
        Button* getButton();
        ProgressBar *getProgressBar();
        AnimatableObject* getAnimatableObject();
};




#endif //DEF_RENDER_ENGINE_HPP
