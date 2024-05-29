#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int j = i;
		while (j != 0) {
			if (j % 10 == 0) cnt++;
			j /= 10;
		}
	}
	cout << cnt << endl;
	return 0;
}