#pragma once
#include <iostream>
#include "./fmod_studio_api/fmod.hpp"
#include "./fmod_studio_api/fmod_errors.h"

#define EXPORT __declspec (dllexport)
#define GM_TRUE 1.0f
#define GM_FALSE 0.0f
#define GM_ERROR -1.0f

class FMODGMS
{
public:
	FMOD_RESULT result;

	FMOD::System *system = nullptr;
	FMOD::Channel* channel = nullptr;
	FMOD::Sound* sound = nullptr;

	EXPORT double sys_create();
	EXPORT double sys_initialize();
	EXPORT double sys_close();

	EXPORT double snd_loadSound(char* filename);
	EXPORT double snd_playSound(double soundIndex, double channelIndex);

private:
	double util_errorChecker();
};