#include <iostream>
using namespace std;
const int MAX = 100;

typedef struct _Interval{
    int start;
    int end;
}interval;

int main() {
    int n;
    cin >> n;
    interval test[MAX];
    for (int i = 0; i < n; i++) 
        cin >> test[i].start >> test[i].end;

    for (int j = n; j > 0; j--) {
        interval max = test[0];
        int idx = 0;
        for (int i = 0; i < j; i++) {
            if (max.start < test[i].start) {
                max = test[i];
                idx = i;
            }
            else if (max.start == test[i].start) {
                if (max.end < test[i].end) {
                    max = test[i];
                    idx = i;
                }
            }
        }
        interval tmp = test[j - 1];
        test[j - 1] = test[idx];
        test[idx] = tmp;
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << test[i].start << " " << test[i].end << endl;
    return 0;
}