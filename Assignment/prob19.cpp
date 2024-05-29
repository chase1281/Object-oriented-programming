#include <iostream>
using namespace std;

int abs(int num1, int num2) {
    if (num1 > num2) return num1 - num2;
    return num2 - num1;
}

int main() {
    int n;
    cin >> n;
    int data[100];
    for (int i = 0; i < n; i++)
        cin >> data[i];

    int k;
    cin >> k;
    int min = abs(k,data[0]);
    int idx = 0;
    for(int i = 0; i < n; i++)
        if (min > abs(k, data[i])) {
            min = abs(k, data[i]);
            idx = i;
        }
    cout << data[idx] << endl;
    return 0;
}