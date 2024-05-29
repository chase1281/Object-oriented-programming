#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> words;
	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		words.push_back(word);
	}

	for (int i = words.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (words[j].length() > words[j + 1].length()) {
				swap(words[j], words[j + 1]);
			}
			else if (words[j].length() == words[j + 1].length()) {
				if(words[j] > words[j+1])
					swap(words[j], words[j + 1]);
			}			
		}
	}
	for (auto s : words)
		cout << s << endl;
	return 0;
}