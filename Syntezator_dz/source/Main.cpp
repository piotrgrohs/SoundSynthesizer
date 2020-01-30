/*
Created by Piotr Grohs
*/

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "bass.h"
#include "BassExtension.h"
#include "FileN.h"
#include "Sound.h"
#include "Argument.h"

void main(int argc, char **argv)
{
	BASS_INFO info;
	HSTREAM stream;
	BassExtension bassextension;
	Sound sound;
	DWORD  buflen;
	FileN fileN;
	Argument argument(argc, argv);

	if (argument.existNameOfFile) {
		// check the correct BASS was loaded
		if (HIWORD(BASS_GetVersion()) != BASSVERSION) {
			printf("An incorrect version of BASS.DLL was loaded");
			return;
		}

		BASS_SetConfig(BASS_CONFIG_VISTA_TRUEPOS, 0); // allows lower latency on Vista and newer
		BASS_SetConfig(BASS_CONFIG_UPDATEPERIOD, 10); // 10ms update period
													  // initialize default output device (and measure latency)
		if (!BASS_Init(-1, 44100, BASS_DEVICE_LATENCY, 0, NULL))
			bassextension.Error("Can't initialize device");

		BASS_GetInfo(&info);
		BASS_SetConfig(BASS_CONFIG_BUFFER, 10 + info.minbuf + 1); // default buffer size = update period + 'minbuf' + 1ms extra margin
		buflen = BASS_GetConfig(BASS_CONFIG_BUFFER);
		if (!info.freq) info.freq = 44100; // if the device's output rate is unknown default to 44100 Hz
		stream = BASS_StreamCreate(44100, 2, 0, BassExtension::WriteStream, &bassextension); // create a stream (stereo for effects)
		BASS_ChannelPlay(stream, FALSE); // start it

		string nameOfFile = argument.nameOfFile, temp;
		string keyWords = fileN.ReadFile(nameOfFile);

		if (sound.Check(keyWords)) { // checking if Notes are correct from file
			cout << "Play...  file: " << nameOfFile << endl;
			for (int i = 0; i < keyWords.length(); i++) {
				int note = sound.Library(keyWords[i]); // library of Notes
				if (note == -1) {
					Sleep(300);
				}
				else {
					bassextension.pos[note] = 0;
					bassextension.vol[note] = MAXVOL + DECAY / 2;
					Sleep(200);
					bassextension.vol[note] -= DECAY;
					Sleep(200);
				}
			}
		}
		else {
			cout << "file damaged or unknown format." << endl;
		}
		BASS_Free();
	}
}
