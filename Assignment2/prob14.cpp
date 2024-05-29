#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	ifstream infile("harry.txt");
	vector<string> words;
	string word;
	while (infile >> word) {
		if(find(words.begin(), words.end(), word) == words.end())
			words.push_back(word);
	}
	sort(words.begin(), words.end());

	string newword;
	cin >> newword;
	int cnt = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].substr(0, newword.length()) == newword) {
			cout << words[i] << endl;
			cnt++;
		}
	}
	cout << cnt << endl;
	infile.close();
	return 0;
}