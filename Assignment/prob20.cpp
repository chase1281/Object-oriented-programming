#include <iostream>
using namespace std;

int main() {
    int data1[100], data2[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data1[i];
    int k;
    cin >> k;
    if (k >= n) cin >> k;

    for (int i = 0; i < n; i++) 
        data2[(i+k) % n] = data1[i];
    for (int i = 0; i < n; i++)
        cout << data2[i] << " ";
    cout << endl;
    return 0;
}