/*Class includes functionality of files, like reading or creating*/
#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class FileN
{
public:
	FileN();
	~FileN();
	void CreateConfig();
	string ReadFile(string nameOfFile);
private:
	void CreateNew(string nameOfFile);
	bool IfExist(string nameOfFile);
};

