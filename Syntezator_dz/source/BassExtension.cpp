#include "BassExtension.h"



BassExtension::BassExtension()
{

}


BassExtension::~BassExtension()
{
}

void BassExtension::Error(const char * text)
{
	printf("Error(%d): %s\n", BASS_ErrorGetCode(), text);
	BASS_Free();
	ExitProcess(0);
}

DWORD BassExtension::WriteStream(HSTREAM handle, void * buffer, DWORD length, void * user)
{
	{
		return static_cast<BassExtension *>(user)->WriteStream(handle, static_cast<short *>(buffer), length);
	}
}

DWORD BassExtension::WriteStream(HSTREAM handle, short * buffer, DWORD length)
{
	int k, c, s;
	float omega;
	memset(buffer, 0, length);
	for (k = 0; k < KEYS; k++) {  
		if (!vol[k]) continue;
		omega = 2 * M_PI*pow(2.0, (k + 3) / 12.0)*440.0 / 44100;
		for (c = 0; c < length / sizeof(short); c += 2) {
			s = buffer[c] + sin(pos[k])*vol[k];
			if (s > 32767) s = 32767;
			else if (s < -32768) s = -32768;
			buffer[c + 1] = buffer[c] = s; // left and right channels are the same
			pos[k] += omega;
			if (vol[k] < MAXVOL) {
				vol[k] -= DECAY;
				if (vol[k] <= 0) { // faded-out
					vol[k] = 0;
					break;
				}
			}
		}
		pos[k] = fmod(pos[k], 2 * M_PI);
	}
	return length;
}

