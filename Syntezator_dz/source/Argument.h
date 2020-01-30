/*Class includes arguments from main()*/
#pragma once
#include <iostream>
#include <string>

using namespace std;
class Argument
{
public:
	string nameOfFile;
	bool existNameOfFile = false;
	Argument();
	Argument(int argc, char ** argv);
	~Argument();
private:
	bool CheckForFile(char * argv);
	bool CheckForAdds(char * argv);
	string ToString(char * argv);
	int LenghtChar(char * argv);
private:
	void Helper();
};

