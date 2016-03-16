/*!
 * \file AnimatableObject.hpp
 * \brief Anime an sprite
 * \author Aredhele
 * \version 0.1
 * \date 2016-01-02
 */

#ifndef DEF_ANIMATABLE_OBJECT
#define DEF_ANIMATABLE_OBJECT

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

		AnimationState m_state;

	public:
		// Constructor
		AnimatableObject();

		// Destructor
		~AnimatableObject();

		// Methods
		void create(std::string id, int x, int y, 
		sf::Texture * texture, bool repeat, 
		float duration, int h, int w, int step);

		virtual void draw(sf::RenderWindow * window);
		virtual std::string eventMousePressed(sf::Event * e);
		virtual std::string eventMouseMoved(sf::Event * e);
		virtual void eventTextEntered(sf::Event * e);
		virtual void update(double frameTime);
		void play();
		bool isStopped();

		void start();
		void pause();
		void stop();
};

#endif // DEF_ANIMATABLE_OBJECT