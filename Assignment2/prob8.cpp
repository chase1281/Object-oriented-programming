#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string Long(const string& str1, const string& str2) {
	int len = min(str1.length(), str2.length());
	int i;
	for (i = 0; i < len; i++)
		if (str1[i] != str2[i])
			break;
	return str1.substr(0, i);
}

int main() {
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i < n; i++)
		cin >> words[i];
	string prefix = words[0];
	for (int i = 1; i < n; i++)
		prefix = Long(prefix, words[i]);
	if (!prefix.empty())
		cout << prefix << endl;
	else cout << "nothing" << endl;
	return 0;
}