#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string line;
	while (1) {
		getline(cin, line);
		if (line == "exit") break;
		string result;
		bool prevspace = false;
		for (char c : line) {
			if (!isspace(c)) {
				result += c;
				prevspace = false;
			}
			else {
				if (!prevspace) {
					result += ' ';
					prevspace = true;
				}
			}
		}
		result.erase(result.find_last_not_of(" \t") + 1);
		result.erase(0, result.find_first_not_of(" \t"));
		cout << result << ":" << result.length() << endl;
	}

	return 0;
}