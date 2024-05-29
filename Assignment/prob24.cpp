#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    int data[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];

    int idx = 0;
    for (int j = n; j > 0; j--) {
        int max = data[0];
        for (int i = 0; i < j; i++) 
            if (max <= data[i]) {
                max = data[i];
                idx = i;
            }
        int tmp = data[j - 1];
        data[j - 1] = data[idx];
        data[idx] = tmp;
    }
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}