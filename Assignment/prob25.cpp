#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    cin >> n;
    int data1[MAX], data2[MAX];
    for (int i = 0; i < n; i++)
        cin >> data1[i];
    
    int idx = 0;
    for (int j = n; j > 0; j--) {
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
    for (int i = 1; i <= n; i++) 
        if (data1[i-1] != data1[i]) data2[idx++] = data1[i-1];
    
    cout << idx << ": ";
    for (int i = 0; i < idx; i++) 
        cout << data2[i] << " ";
    cout << endl;
    return 0;
}