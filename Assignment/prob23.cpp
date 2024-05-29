#include <iostream>
using namespace std;
const int MAX = 100;

int Binary(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            cout << "duplicate" << endl;
            return 1;
        }
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 0;
}

int main() {
    int data[MAX];
    int val, size = 0;
    while(1) {
        cin >> val;
        if (val == -1) break;
        if (Binary(data, size, val) == 1) continue;
        int idx = size;
        while (idx > 0 && data[idx - 1] > val) {
            data[idx] = data[idx-1];
            idx--;
        }
        data[idx] = val;
        size++;
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    return 0;
}