#include <iostream>
#include <vector>
using namespace std;

int compare_num(int num1, int num2) {
	if (num1 == num2) return 0;
	int a = 1, b = 1;
	while (a <= num1)
		a *= 10;
	while (b <= num2)
		b *= 10;

	while (a > 0 && b > 0) {
		if (num1 / a < num2 / b) return -1;
		else if (num1 / a > num2 / b) return 1;
		else {
			num1 %= a;
			num2 %= b;
			a /= 10;
			b /= 10;
		}
	}
	if (a == 0) return -1;
	else if (b == 0) return 1;
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) 
		cin >> num[i];
	for (int i = 0; i < n - 1; i++)
		for(int j = i+1; j < n; j++)
		if (compare_num(num[i], num[j]) == 1) {
			int tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
		}
	for (auto v : num)
		cout << v << " ";
	cout << endl;
	return 0;
}