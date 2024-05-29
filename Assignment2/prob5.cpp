#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	ifstream infile("sample_lines.txt");
	string line;
	vector<string> lines;
	vector<int> count;
	while (getline(infile, line)) {
		if (line == "") continue;
		string str = "";
		bool prevspace = false;
		for (char c : line) {
			if (!isspace(c)) {
				str += c;
				prevspace = false;
			}
			else {
				if (!prevspace) {
					str += ' ';
					prevspace = true;
				}
			}
		}
		str.erase(str.find_last_not_of(" \t") + 1);
		str.erase(0, str.find_first_not_of(" \t"));
		int cnt = 1;
		for (char c : str) 
			if (isspace(c))
				cnt++;
		lines.push_back(str);
		count.push_back(cnt);
	}
	
	for (int i = lines.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (count[j] < count[j + 1]) {
				int tmp = count[j+1];
				count[j + 1] = count[j];
				count[j] = tmp;

				string temp = lines[j + 1];
				lines[j + 1] = lines[j];
				lines[j] = temp;
			}
		}
	}

	for (int i = 0; i < lines.size(); i++)
		cout << lines[i] << ":" << count[i] << endl;
	infile.close();
	return 0;
}