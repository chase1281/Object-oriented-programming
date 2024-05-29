#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int n;
	int i;
	cin >> n;
	int* arr = (int*)malloc(sizeof(int) * n);
	if (arr == NULL) return -1;

	int min = -1;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= 0) min = arr[i];
	}
	for (i = 0; i < n; i++)
		if (min > arr[i] && arr[i] >= 0) min = arr[i];

	if (min == -1) cout << "-1" << endl;
	else cout << min << endl;
	free(arr);
	return 0;
}