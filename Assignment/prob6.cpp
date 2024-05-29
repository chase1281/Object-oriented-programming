#include <iostream>
using namespace std;

int main() {
	int n, val;
	int max = 0, min = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		if (i == 0) max = min = val;
		if (max < val) max = val;
		else if (min > val) min = val;
		cout << (max - min) << " ";
	}
	return 0;
}