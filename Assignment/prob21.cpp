#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int data[100];
    for (int i = 0; i < n; i++)
        cin >> data[i];

    int leader = data[0];
    int cnt = 1;
    int idx = 0;
    int temp[100];
    temp[idx] = leader;
    for (int i = 1; i < n; i++) {
        if (leader <= data[i]) {
            leader = data[i];
            temp[++idx] = leader;
            cnt++;
        }
    }
    cout << cnt << ": ";
    for (int i = 0; i <= idx; i++)
        cout << temp[i] << " ";
    cout << endl;
    return 0;
}