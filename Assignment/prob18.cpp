#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int data[10] = { 0 };
    while (N != 0) {
        data[N % 10]++;
        N /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 9) cout << data[i];
        else cout << data[i] << ", ";
    }
    cout << endl;
    return 0;
}