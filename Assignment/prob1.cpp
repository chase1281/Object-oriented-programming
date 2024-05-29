#include <iostream>
using namespace std;

int Fibonacci(int n) {
	if (n == 0 || n == 1) return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
	int n;
	cout << "2이상 30이하의 정수를 입력하세요: ";
	cin >> n;
	if (n < 2 || n > 30) {
		cout << "Error!! 2이상 30이하의 정수를 입력하세요." << endl;
		cin >> n;
	}
	cout << Fibonacci(n) << endl;
	return 0;
}