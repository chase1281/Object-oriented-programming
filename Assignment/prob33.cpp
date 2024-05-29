#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 100;
int main() {
    int N;
    cin >> N;
    if (N % 2 == 0) cin >> N;
    srand((unsigned int)time(NULL));

    int cnt = 0;
    for (int i = 0; i < 100000; i++) {
        int data[MAX][MAX] = { 0 };
        int x = N / 2;
        int y = N / 2;
        data[x][y] = 1;
        while (!(x == 0 || x == N - 1 || y == 0 || y == N - 1)) {
            if (data[x - 1][y] == 1 && data[x + 1][y] == 1 && data[x][y + 1] == 1 && data[x][y - 1] == 1) break;
            int dir = rand() % 4;
            switch (dir)
            {
            case 0: // ╩С
                if (x > 0 && data[x-1][y] == 0) {
                    data[x-1][y] = 1;
                    x--;
                }
                break;
            case 1: // го
                if (x < N - 1 && data[x+1][y] == 0) {
                    data[x+1][y] = 1;
                    x++;
                }
                break;
            case 2: // аб
                if (y > 0 && data[x][y-1] == 0) {
                    data[x][y-1] = 1;
                    y--;
                }
                break;
            case 3: // ©Л
                if (y < N - 1 && data[x][y+1] == 0) {
                    data[x][y+1] = 1;
                    y++;
                }
                break;
            default:
                break;
            }
        }
        if (x == 0 || x == N - 1 || y == 0 || y == N - 1) cnt++;
    }
    cout << (double)cnt / 100000 << endl;
    return 0;
}