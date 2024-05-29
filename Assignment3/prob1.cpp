#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sorted_merge(vector<string>& first, vector<string>& second) {
	vector<string> merged;
	auto it1 = first.begin();
	auto it2 = second.begin();
	while (it1 != first.end() && it2 != second.end()) {
		if (*it1 > *it2) {
			merged.push_back(*it2);
			it2++;
		}
		else {
			merged.push_back(*it1);
			it1++;
		}
	}
	while (it1 != first.end()) {
		merged.push_back(*it1);
		it1++;
	}
	while (it2 != second.end()) {
		merged.push_back(*it2);
		it2++;
	}
	first = merged;
}

int main() {
	int m, n;
	string str;
	vector<string> first, second;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> str;
		first.push_back(str);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		second.push_back(str);
	}
	sorted_merge(first, second);
	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}