#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cout << "a <= b �̰� c <= d�� �ǵ��� ������ �Է��Ͻÿ�: ";
	cin >> a >> b >> c >> d;
	if ((d < a) || (c > b)) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}