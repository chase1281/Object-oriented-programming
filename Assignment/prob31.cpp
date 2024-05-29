#include <iostream>
using namespace std;

const int MAX = 7;
int main() {
    int data1[MAX], data2[MAX];
    for (int i = 0; i < MAX; i++)
        cin >> data1[i];

    int idx = 0;
    for (int j = MAX; j > 0; j--) {
        int max = data1[0];
        for (int k = 0; k < j; k++) {
            if (max <= data1[k]) {
                max = data1[k];
                idx = k;
            }
        }
        int tmp = data1[j - 1];
        data1[j - 1] = data1[idx];
        data1[idx] = tmp;
    }
    idx = 0;
    for (int i = 1; i <= MAX; i++)
        if (data1[i - 1] != data1[i]) data2[idx++] = data1[i - 1];

    int flag = 0;
    for (int i = 0; i < idx-4; i++) {
        if (data2[i + 1] - data2[i] == 1 && data2[i + 2] - data2[i] == 2 && data2[i + 3] - data2[i] == 3 && data2[i + 4] - data2[i] == 4) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}