#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

string cleanword(string word) {
	string str;
	for (char c : word) {
		if (isalnum(c))
			str += tolower(c);
	}
	return str;
}

int main() {
	ifstream infile("sample.txt");
	string line;
	vector<string> lines;
	while (infile >> line) {
		line = cleanword(line);
		if (find(lines.begin(), lines.end(), line) == lines.end())
			lines.push_back(line);
	}

	sort(lines.begin(), lines.end());
	for (const auto &s : lines)
		cout << s << endl;
	infile.close();
	return 0;
}