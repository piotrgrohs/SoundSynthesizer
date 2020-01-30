#include "Argument.h"


Argument::Argument()
{
}
Argument::Argument(int argc, char **argv)
{
	int lenght;
	string nameOfFile;
	if (argc >= 1) {
		for (int i = 1; i < argc; i++) {
			if (CheckForFile(argv[i])&!existNameOfFile) {
				existNameOfFile = true;
				this->nameOfFile = ToString(argv[i]);
			}
			else if (CheckForFile(argv[i]) & existNameOfFile) {
				cout << "to many parametrs with file name" << endl;
			}
			else if (CheckForAdds(argv[i])) {
				Helper();
			}
			else {
				cout << "Type -h for help" << endl;
				cout << "----------------" << endl;
				Helper();
			}

		}
	}
}
string Argument::ToString(char *argv) {
	string word;
	int lenght = LenghtChar(argv);
	for (int i = 0; i < lenght; i++) {
		word += argv[i];
	}
	return word;
}
bool Argument::CheckForFile(char *argv) {
	int lenght = LenghtChar(argv) - 1;
	if (argv[lenght - 4] == '.') {
		if (argv[lenght - 3] == 't'&&
			argv[lenght - 2] == 'x'&&
			argv[lenght - 1] == 't') {
			return true;
		}
	}
	else {
		return false;
	}

}
bool Argument::CheckForAdds(char *argv) {
	int lenght = LenghtChar(argv) - 1;
	if (argv[0] == '-') {
		if (argv[1] == 'h') {
			return true;
			}
	}
	else {
		return false;
	}

}
int Argument::LenghtChar(char * argv) {
	char temp = argv[0];
	int i = 0;
	while (temp != '\0') {
		temp = argv[i];
		i++;
	}
	return i;
}
void Argument::Helper() {
	cout << "Program : Syntezator dzwieku" << endl;
	cout << "----------------------------" << endl;
	cout << "<file.txt> to play a notes from file" << endl;
	cout << "-h showing help" << endl;
}

Argument::~Argument()
{
}
