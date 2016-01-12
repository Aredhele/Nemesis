/*!
 * \file AnimatableObject.hpp
 * \brief Anime an sprite
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_ANIMATABLE_OBJECT_HPP
#define DEF_ANIMATABLE_OBJECT_HPP

#include "VisualObject.hpp"
#include <iostream>

class AnimatableObject : public VisualObject
{
    enum AnimationState
    {
        PLAY,
        PAUSE,
        STOP
    };

private:
    // Member
    float m_animduration;
    bool m_repeat;
    int m_lenght;
    int m_currentStep;
    int m_frameHeight;
    int m_frameWidth;
    bool m_loading;

    AnimationState m_state;

public:
    // Constructor
    AnimatableObject(sf::Vector2f position, std::string pathToTexture);

    // Destructor
    ~AnimatableObject();

    // Methods
    void init(bool repeat,
              float duration, int h, int w, int step);

    virtual void draw(sf::RenderWindow * window);
    virtual void update(double frameTime);

    void loading(bool loading);
    bool isLoading();

};

#endif // DEF_ANIMATABLE_OBJECT_HPP