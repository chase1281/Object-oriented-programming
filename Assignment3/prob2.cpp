#include <iostream>
#include <vector>
using namespace std;

void compute_set(vector<int>& A, vector<int>& B) {
	vector<int> res;
	auto it1 = A.begin();
	auto it2 = B.begin();
	while (it1 != A.end() && it2 != B.end()) {
		if (*it1 > *it2) {
			res.push_back(*it2);
			it2++;
		}
		else if (*it1 < *it2) {
			res.push_back(*it1);
			it1++;
		}
		else {
			it1++;
			it2++;
		}
	}
	while (it1 != A.end()) {
		res.push_back(*it1);
		it1++;
	}
	while (it2 != B.end()) {
		res.push_back(*it2);
		it2++;
	}
	A = res;
}

int main() {
	int m, n, k;
	vector<int> first, second;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		first.push_back(k);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		second.push_back(k);
	}
	compute_set(first, second);
	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}