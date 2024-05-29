#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "하나의 양의 정수를 입력하시오: ";
	cin >> n;
	double sum = 1.0;
	for (int i = 1; i <= n; i++) {
		double val = 1.0;
		for (int j = i; j > 0; j--)
			val *= (-1) / 2.0;
		sum += val;
	}
	cout << "합: " << sum << endl;
	return 0;
}