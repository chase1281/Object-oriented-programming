#include <iostream>
using namespace std;

double Factorial(int val) {
	if (val == 1) return 1.0;
	return Factorial(val - 1) * val;
}

int main() {
	int n;
	cout << "하나의 양의 정수를 입력하시오: ";
	cin >> n;
	double sum = 0.0;
	for (int i = 1; i <= n; i++) 
		sum += 1.0 / Factorial(i);
	cout << "합: " << sum << endl;
	return 0;
}