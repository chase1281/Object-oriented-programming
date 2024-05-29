#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	int cnt = 0;
	for (int i = 2; i <= 100; i++)
		for (int j = i + 1; j <= 100; j++)
			for (int k = j + 1; k <= 100; k++)
				if (gcd(j, i) == 1 && gcd(k, i) == 1 && gcd(k, j) == 1) cnt++;
	cout << cnt << endl;
	return 0;
}