#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int data[101];

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
        sum += data[i];
    }
    double avg = (double)sum / n;

    double sd = 0;
    for (int i = 1; i <= n; i++) 
        sd += (data[i] - avg) * (data[i] - avg);
    sd = sqrt(sd / n);
    cout << avg << " " << sd << endl;
    return 0;
}