/*Class includes funcionality of bass.dll with files*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Sound
{
public:
	int Library(char sound);
	bool Check(string text);
	Sound();
	~Sound();
};

