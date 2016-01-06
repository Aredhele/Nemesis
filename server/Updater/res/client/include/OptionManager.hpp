/*!
 * \file OptionManager.hpp
 * \brief Contains all game options
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-28
 */

#ifndef DEF_OPTION_MANAGER_HPP
#define DEF_OPTION_MANAGER_HPP

#include "Manager.hpp"

class OptionManager : public Manager
{
	public:
		// Constructor
		OptionManager(bool debug);

		// Destructor
		~OptionManager();

		// Tokens
};

#endif // DEF_OPTION_MANAGER_HPP