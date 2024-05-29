#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream infile("input3.txt");
	vector<string> lines;
	vector<int> count;
	string str;

	while (infile >> str) {
		for (char& c : str)
			c = tolower(c);
		int j = 0;
		for (; j < lines.size(); j++)
			if (lines[j] == str)
				break;
		if (j < lines.size())
			count[j]++;
		else {
			lines.push_back(str);
			count.push_back(1);
		}

	}
	for (int i = lines.size() - 1; i > 0; i--) {
		for (int k = 0; k < i; k++)
			if (count[k] < count[k + 1]) {
				int temp = count[k];
				count[k] = count[k + 1];
				count[k + 1] = temp;

				string tmp = lines[k];
				lines[k] = lines[k + 1];
				lines[k + 1] = tmp;
			}
			else if (count[k] == count[k + 1]) {
				if (lines[k] > lines[k + 1]) {
					string tmp = lines[k];
					lines[k] = lines[k + 1];
					lines[k + 1] = tmp;

					int temp = count[k];
					count[k] = count[k + 1];
					count[k + 1] = temp;
				}
			}
	}
	for (int i = 0; i < lines.size(); ++i) {
		cout << lines[i] << ":" << count[i] << endl;
	}
	infile.close();
	return 0;
}