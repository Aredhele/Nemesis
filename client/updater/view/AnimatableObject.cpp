/*!
 * \file AnimatableObject.cpp
 * \brief Anime an sprite
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#include "view/AnimatableObject.hpp"
/*!
 * \brief Constructor
 * \return None
 */
AnimatableObject::AnimatableObject(sf::Vector2f position, std::string pathToTexture) :
        VisualObject(position, pathToTexture) {

}

/*!
 * \brief Destructor
 */
AnimatableObject::~AnimatableObject() {
    // None
}

/*!
 * \brief Init methode
 * \param id The id of the object
 * \param x The x abs position of the sprite
 * \param y The y abs position of the sprite
 * \param texture The texture of the main sprite
 */
void AnimatableObject::init(bool repeat, float duration, int h,
                            int w, int step) {

    m_animduration = duration;
    m_repeat = repeat;
    m_frameHeight = h;
    m_frameWidth = w;
    m_lenght = step;
    m_currentStep=0;
    m_loading = false;
    m_state = AnimationState::PLAY;

    m_sprite.setTextureRect(sf::IntRect(
            0, 0,
            m_frameWidth, m_frameHeight));
}

/*!
 * \brief Draw all object in the panel
 * \param window The pointer on window
 */
void AnimatableObject::draw(sf::RenderWindow * window) {

    if(m_hidden) return;
    window->draw(m_sprite);
}

/*!
 * \brief Update all component
 * \param frameTime The time elapsed since last frame
 */
void AnimatableObject::update(double frameTime) {
    if (m_currentStep>=35)
        m_loading=false;

    if(!m_loading)
        return;

    if(m_state == AnimationState::PLAY) {
        m_timeElapsed += frameTime;

        if(m_timeElapsed >= m_animduration) {
            m_timeElapsed = 0;
            if(m_currentStep + 1 >= m_lenght) {
                if(m_repeat) m_currentStep = 0;
                else m_state = AnimationState::STOP;
            } else {
                m_currentStep++;
            }

            m_sprite.setTextureRect(sf::IntRect(
                    m_currentStep * m_frameWidth, 0,
                    m_frameWidth, m_frameHeight));
        }
    }

    std::cout << "Step : " << m_currentStep << std::endl;
}

void AnimatableObject::loading(bool loading){
    m_loading = loading;
}

bool AnimatableObject::isLoading(){
    return m_loading;
}