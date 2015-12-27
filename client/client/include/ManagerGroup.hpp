/*!
 * \file ManagerGroup.hpp
 * \brief Store all managers
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#ifndef DEF_MANAGER_GROUP_HPP
#define DEF_MANAGER_GROUP_HPP

#include "MusicManager.hpp"
#include "TextureManager.hpp"

class ManagerGroup
{
	public:
		// Constructor
		ManagerGroup();

		// Destructor
		~ManagerGroup();

		// Token
		MusicManager * ptr_musicManager;
		TextureManager * ptr_textureManager;
};

#endif // DEF_MANAGER_GROUP_HPP