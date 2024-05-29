#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
    int n;
    cin >> n;
    int data[MAX];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    for(int i = 0; i < n-1; i++)
        for (int j = i + 1; j < n; j++)
            if (data[i] > data[j]) cnt++;
    cout << cnt << endl;
    return 0;
}