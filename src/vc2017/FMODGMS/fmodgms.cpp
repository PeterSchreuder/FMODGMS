#include "fmodgms.hpp"

EXPORT double FMODGMS::sys_create()
{
	result = FMOD::System_Create(&system);      // Create the main system object.
	util_errorChecker();

	std::cout << "FMOD System created" << std::endl;
	return GM_TRUE;
}

EXPORT double FMODGMS::sys_initialize()
{
	result = system->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
	util_errorChecker();

	std::cout << "FMOD System initialized" << std::endl;
	return GM_TRUE;
}

EXPORT double FMODGMS::sys_close()
{
	result = system->release();
	util_errorChecker();

	std::cout << "FMOD System closed" << std::endl;
	return GM_TRUE;
}

EXPORT double FMODGMS::snd_loadSound(char* filename)
{
	result = system->createSound(filename, FMOD_DEFAULT, 0, &sound);

	if (util_errorChecker() == GM_TRUE)
	{
		return 0;
	}

	else
		return GM_ERROR;
}

EXPORT double FMODGMS::snd_playSound(double soundIndex, double channelIndex)
{
	int i = (int)round(soundIndex);
	int c = (int)round(channelIndex);

	result = system->playSound(sound, 0, false, &channel);

	return util_errorChecker();
}

double FMODGMS::util_errorChecker()
{
	if (result != FMOD_OK)
	{
		std::cout << "FMOD error! (" << result << ") " << FMOD_ErrorString(result) << std::endl;
		return GM_FALSE;
	}

	return GM_TRUE;
}