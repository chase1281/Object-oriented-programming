#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    cin >> n;
    int data[MAX];
    for (int i = 0; i < n; i++)
        cin >> data[i];
    int k;
    cin >> k;

    int max = 0;
    for (int i = 0; i < n; i++) {
        int len = 0;
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += data[j];
            if (sum <= k) len++;
            else break;
        }
        if (max < len) 
            max = len;
    }
    cout << max << endl;
    return 0;
}