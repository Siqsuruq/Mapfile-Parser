#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc == 2) {
		string filename = argv[1];
		cout << "Trying to open " << filename << " file, and strip spaces and comments." << endl;
		cout << "------------------------------------" << endl;
		ifstream input;

		input.open(filename);
		if (!input.is_open()) {
			return 1;
		}

		while (input) {
			string line;
			getline(input >> ws, line);

			regex self_regex("#.*$", regex::icase);
			string newtext = regex_replace(line, self_regex, "");

			if (!newtext.empty()) {
				cout <<  newtext << endl;
			}
		}
	}
	else {
		cout << "Please provide Mapfile argument";
	}

	return 0;
}