#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "�ϳ��� ���� ������ �Է��Ͻÿ�: ";
	cin >> n;
	double sum = 1.0;
	for (int i = 1; i <= n; i++) {
		double val = 1.0;
		for (int j = i; j > 0; j--)
			val *= (-1) / 2.0;
		sum += val;
	}
	cout << "��: " << sum << endl;
	return 0;
}