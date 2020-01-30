#include "FileN.h"



FileN::FileN()
{
}


FileN::~FileN()
{
}

void FileN::CreateNew(string nameOfFile)
{
	fstream file;
	file.open(nameOfFile, fstream::out);
	if (!file.good()) {
		cout << "Something wrong when create file" << endl;
	}
	file.close();
}
bool FileN::IfExist(string nameOfFile) {
	fstream file;
	file.open(nameOfFile, fstream::in);
	if (file.good()) {
		return true;
	}
	else return false;

}
string FileN::ReadFile(string nameOfFile) {
	string Temp, Text;
	if (IfExist(nameOfFile)) {
		fstream file;
		file.open(nameOfFile, ios::in | ios::out);
		while (!file.eof()) {
			getline(file, Temp);
			Text = Text +'.'+ Temp;
		}
		file.close();
		return Text;
	}
	else {
		cout << "file not exists" << endl;
		return "";
	}
}


void FileN::CreateConfig()
{
	if (!IfExist("config.txt"))
		CreateNew("config.txt");
	fstream file;

}
