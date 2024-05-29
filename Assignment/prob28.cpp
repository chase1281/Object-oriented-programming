#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    cin >> n;
    int data[MAX];
    int len = 1;
    int max = 1;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    for (int i = 1; i < n; i++) {
        if (data[i - 1] <= data[i]) {
            len++;
            if (max < len) max = len;
        }
        else len = 1;
    }
    cout << max << endl;
    return 0;
}