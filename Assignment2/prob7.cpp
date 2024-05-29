#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string word;
	vector<string> words;
	while (1) {
		cin >> word;
		if (word == "exit") break;
		bool dup = false;
		for (auto s : words) {
			if (s == word) {
				cout << "duplicate" << endl;
				dup = true;
				break;
			}
		}
		if (dup == true) continue;
		words.push_back(word);
		sort(words.begin(), words.end());
		for (int i = 0; i < words.size(); i++)
			cout << words[i] << " ";
		cout << endl;
	}
	return 0;
}