#include <iostream>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

int main() {
	ifstream file;
	file.open("toygamecopy.json");

	string buffer;
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			buffer += line;
			json j3 = json::parse(buffer);
			for (json::iterator it = j3.begin(); it != j3.end(); ++it) {
				if (it.key() == "summary")
					cout << "key: " << it.key() << "\tvalue: " << it.value() << endl;
			}
			buffer.clear();
			getchar();
		}
		file.close();
	}

	return 0;
}