#include <iostream>
using namespace std;
const int MAX = 100;

int Profit(int arr[], int n) {
    int buy = -1;
    int margin = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            if (buy == -1) buy = arr[i - 1];
        }
        else if (arr[i - 1] > arr[i]) {
            if (buy != -1) margin += arr[i-1] - buy;
            buy = -1;
        }
    }
    if (buy != -1 && arr[n - 1] > buy) margin += arr[n - 1] - buy;
    return margin;
}

int main() {
    int data[MAX];
    int i = 0;
    while (1) {
        cin >> data[i];
        if (data[i] == -1) break;
        i++;
    }
    cout << Profit(data, i) << endl;
    return 0;
}