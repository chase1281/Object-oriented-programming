#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

typedef struct _interval {
    int start;
    int end;
}interval;

int main() {
    int N;
    cin >> N;
    interval arr[MAX];
    for (int i = 0; i < N; i++)
        cin >> arr[i].start >> arr[i].end;

    int maxlen = 0, len = 0;
    int start = 0, end = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i + 1; j < N; j++) {
            len = min(arr[i].end, arr[j].end) - max(arr[i].start, arr[j].start);
            if (maxlen < len) {
                maxlen = len;
                start = i;
                end = j;
            }
        }
    }
    cout << "[" << arr[start].start << ", " << arr[start].end << "]" << endl;
    cout << "[" << arr[end].start << ", " << arr[end].end << "]" << endl;
    return 0;
}