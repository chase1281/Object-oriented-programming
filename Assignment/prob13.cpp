#include <iostream>
using namespace std;

int main() {
	int cnt = 0;
	for (int i = 0; i <= 100; i++) 
		for (int j = 0; j <= 100; j++)
			if(i*i + j*j <= 10000 && j >= i/3.0 && j <= 2*i/3.0)
				cnt++;
	cout << cnt << endl;
	return 0;
}