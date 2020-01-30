#include "Sound.h"

int Sound::Library(char sound) {
	switch (sound)
	{
	case 'A':
		return 1;
		break;
	case 'B':
		return 3;
		break;
	case 'C':
		return 6;
		break;
	case 'D':
		return 9;
		break;
	case 'E':
		return 12;
		break;
	case 'F':
		return 15;
		break;
	case 'G':
		return 18;
		break;
	case '.':
		return -1;
		break;
	default:
		return 21;
		break;
	}
}

bool Sound::Check(string text)
{
	int count = 0;
	for (int i = text.length(); i < 0; i--) {
		if (Library(text[i]) == 21) {
			return false;
			break;
		}
		else {
			count++;
		}
	}
	if (count == text.length()) {
		return true;
	}
	
}

Sound::Sound()
{
}


Sound::~Sound()
{
}
