#include <iostream>
using namespace std;

const int MAX = 100;
int main() {
    int n;
    cin >> n;
    int data[MAX];
    for (int i = 0; i < n; i++)
        cin >> data[i];

    int cnt = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 0) {
            data[i] = 1;
            for (int j = i; j < n; j++) {
                if (data[j] == 1) cnt++;
                else break;
            }
            if (cnt > max) max = cnt;
            data[i] = 0;
            cnt = 0;
        }
        else {
            cnt++;
            if (cnt > max) max = cnt;
        }
    }
    cout << max << endl;
    return 0;
}