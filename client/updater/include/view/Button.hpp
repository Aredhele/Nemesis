#ifndef DEF_BUTTON_HPP
#define DEF_BUTTON_HPP

#include "VisualObject.hpp"
#include "Surrounder.hpp"

class Button : public VisualObject
{
    private:
        bool m_active;
        double m_totalTime;
        sf::Texture m_secondTexture;
        sf::Texture m_oldTexture;
        sf::Sprite m_secondSprite;
        sf::Sprite m_oldSprite;
        bool m_isPress;
        bool m_enable;

    public:
        // Constructor
        Button(sf::Vector2f position, std::string pathToTexture, std::string p);
        Button(sf::Vector2f position, std::string pathToTexture, std::string p, std::string oldTexture);


        // Destructor
        ~Button();

        // Methods
        void draw(sf::RenderWindow * window);
        void handle(sf::Event * e);
        void update(double frameTime);
        void enable(bool enable);

        //Getters
        bool isPress();
};

#endif // DEF_BUTTON_HPP
