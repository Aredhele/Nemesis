/*!
 * \file VideoParam.cpp
 * \brief Store all parameters needed to play a video
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-25
 */

#include "VideoParam.hpp"

/*!
 * \brief Constructor
 * \param frameHeight The height of each frame in pixel
 * \param frameWidth The widht of each frame in pixel
 * \param frameRate The speed of video
 * \param file The input file to read
 */
VideoParam::VideoParam(const ushort frameWidth, 
const ushort frameHeight, const ushort frameRate, 
const ushort frameNumber, const std::string & file)
{

	fWidth = frameWidth;
	fHeight = frameHeight;
	fRate = frameRate;
	fNumber = frameNumber;
	path = file;
}

/*!
 * \brief Destructor
 */
VideoParam::~VideoParam() {
	// None
}