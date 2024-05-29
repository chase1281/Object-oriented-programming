#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cout << "a <= b 이고 c <= d가 되도록 정수를 입력하시오: ";
	cin >> a >> b >> c >> d;
	if ((d < a) || (c > b)) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}