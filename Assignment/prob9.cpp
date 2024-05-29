#include <iostream>
using namespace std;

int main() {
	int coef, expo_x, expo_y;
	cin >> coef >> expo_x >> expo_y;
	if (coef != 0) {

		if (coef != 1 && coef != -1) 
			cout << coef;
		else if (coef == -1) {
			if (expo_x == 0 && expo_y == 0)
				cout << "-1";
			else 
				cout << "-";
		}
		else if (coef == 1)
			if (expo_x == 0 && expo_y == 0)
				cout << "1";

		if (expo_x != 0) {
			if (expo_x != 1)
				cout << "x^" << expo_x;
			else
				cout << "x";
		}

		if (expo_y != 0) {
			if (expo_y != 1)
				cout << "y^" << expo_y;
			else
				cout << "y";
		}
	}
	else cout << "X";
	return 0;
}