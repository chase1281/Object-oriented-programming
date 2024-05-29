#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	getline(cin, str);
	int sum = 0;
	int num = 0;
	bool number = false;
	bool negative = false;
	for (char c : str) {
		if (isdigit(c)) {
			num = num * 10 + (c - '0');
			number = true;
		}
		else if (c == '+') {
			if (number) {
				if (negative)
					sum -= num;
				else
					sum += num;
				num = 0;
			}
			negative = false;
			number = false;
		}
		else if (c == '-') {
			if (number) {
				if (negative)
					sum -= num;
				else
					sum += num;
				num = 0;
			}
			negative = true;
			number = false;
		}
	}
	if (number) {
		if (negative)
			sum -= num;
		else
			sum += num;
	}
	cout << sum << endl;
	return 0;
}