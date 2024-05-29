#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	//정렬
	ifstream infile("shuffled_dict.txt");
	vector<string> words;
	vector<string> dictionary;
	string line;
	while (getline(infile, line)) {
		int tabPos = line.find("\t");
		words.push_back(line.substr(0, tabPos));
		dictionary.push_back(line.substr(tabPos + 1));
	}
	for(int i = words.size()-1; i > 0; i--)
		for (int j = 0; j < i; j++) 
			if (words[j] > words[j + 1]) {
				swap(words[j], words[j + 1]);
				swap(dictionary[j], dictionary[j + 1]);
			}
	//단어 찾기
	string word;
	cin >> word;
	int left = 0;
	int right = words.size() - 1;
	bool found = false;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (words[mid] == word) {
			cout << "Found:" << endl;
			cout << words[mid] << ": " << dictionary[mid] << endl << endl;
			found = true;
			break;
		}
		else if (words[mid] < word) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	if (!found) {
		cout << "Not found" << endl;
		if (right >= 0 && right < words.size()) {
			cout << "- " << words[right] <<  ": " << dictionary[right] << endl;
		}
		if (left < words.size()) {
			cout << "+ " << words[left] << ": " << dictionary[left] << endl;
		}
		cout << endl;
	}
	//접두사
	cout << "Results of prefix search:" << endl;
	for (int i = 0; i < words.size(); i++)
		if (words[i].substr(0, word.length()) == word) 
			cout << words[i] << ": " << dictionary[i] << endl;
	infile.close();
	return 0;
}