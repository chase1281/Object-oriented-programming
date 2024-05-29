#include <iostream>
using namespace std;
#define MAX 100

int main() {
	int data[MAX];
	int cnt = 0, idx = 0;
	while (1) {
		cin >> data[idx];
		if (data[idx] == -1) break;
		idx++;
	}

	if (data[0] <= data[1]) cnt++;
	for (int i = 1; i < idx; i++)
		if (data[i - 1] >= data[i] && data[i] <= data[i + 1]) cnt++;
	if (data[idx - 1] <= data[idx - 2]) cnt++;
	cout << cnt << endl;
	return 0;
}