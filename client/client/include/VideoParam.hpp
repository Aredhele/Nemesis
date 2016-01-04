/*!
 * \file VideoParam.hpp
 * \brief Store all parameters needed to play a video
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#ifndef DEF_VIDEO_PARAM_HPP
#define DEF_VIDEO_PARAM_HPP

#include <string>

class VideoParam
{
	using ushort = unsigned short;

	public:
		// Constructor
		VideoParam(const ushort frameWidth, 
		const ushort frameHeight, const ushort frameRate, 
		const ushort frameNumber, const std::string & file);

		// Destructor
		~VideoParam();

		// Token
		ushort fWidth;
		ushort fHeight;
		ushort fRate;
		ushort fNumber;
		std::string path;
};

#endif // DEF_VIDEO_PARAM_HPP