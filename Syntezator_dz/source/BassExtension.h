#pragma once

#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "bass.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define KEYS 20
#define MAXVOL (0.22*32768) 
#define DECAY (MAXVOL/4000) 
/* Class includes functionality of bass.dll. */
class BassExtension
{
public:
	BassExtension();
	~BassExtension();
	void Error(const char *text);
	static DWORD CALLBACK WriteStream(HSTREAM handle, void *buffer, DWORD length, void *user);
	DWORD CALLBACK WriteStream(HSTREAM handle, short *buffer, DWORD length);
	float vol[KEYS] = { 0 }, pos[KEYS];
private:
};

