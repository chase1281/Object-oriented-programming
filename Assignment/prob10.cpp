#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int v = 1;
	while (v <= N)
		v *= 2;
	v /= 2;

	while (v > 0) {
		if (N >= v) {
			N -= v;
			cout << "1";
			v /= 2;
		}
		else {
			cout << "0";
			v /= 2;
		}
	}
	return 0;
}