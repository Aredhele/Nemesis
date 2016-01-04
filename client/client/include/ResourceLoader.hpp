/*!
 * \file resourceLoader.hpp
 * \brief Load all resources in a thread
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */
 
#ifndef DEF_RESOURCE_LOADER_HPP
#define DEF_RESOURCE_LOADER_HPP

#include <SFML/System.hpp>

#include "ManagerGroup.hpp"

class ResourceLoader
{
	private:
		// Member
		ManagerGroup m_managerGroup;

		sf::Thread m_thread;
		bool m_debug;

		// Methods
		void load();

	public:
		// Constructor
		ResourceLoader(bool debug);

		// Destructor
		~ResourceLoader();

		// Methods
		void start();
		void stop();

		// Getters
		bool getLoadState();
		ManagerGroup * getManager();
};

#endif // DEF_RESOURCE_LOADER_HPP