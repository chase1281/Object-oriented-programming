#include <iostream>
#include <vector>

using namespace std;

class Pos {
public:
    int x;
    int y;
    Pos(int x_, int y_) : x(x_), y(y_) {}
};

int main() {
    const int MAX = 201;
    vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
    Pos currentPos(0, 0);
    visited[100][100] = true;

    while (true) {
        int dir, m;
        cin >> dir >> m;
        if (dir == -1 && m == -1) break;

        int newX = currentPos.x, newY = currentPos.y;
        switch (dir) {
        case 0:
            newY += m;
            break;
        case 1:
            newX += m;
            break;
        case 2:
            newY -= m;
            break;
        case 3:
            newX -= m;
            break;
        }

        bool validMove = true;
        for (int i = 1; i <= m; i++) {
            int checkX = currentPos.x + (dir == 1 ? i : (dir == 3 ? -i : 0));
            int checkY = currentPos.y + (dir == 0 ? i : (dir == 2 ? -i : 0));
            if (visited[checkX + 100][checkY + 100]) {
                validMove = false;
                break;
            }
        }

        if (!validMove) {
            cout << "invalid move" << endl;
        }
        else {
            for (int i = 1; i <= m; i++) {
                int visitX = currentPos.x + (dir == 1 ? i : (dir == 3 ? -i : 0));
                int visitY = currentPos.y + (dir == 0 ? i : (dir == 2 ? -i : 0));
                visited[visitX + 100][visitY + 100] = true;
            }
            currentPos.x = newX;
            currentPos.y = newY;
            cout << currentPos.x << " " << currentPos.y << endl;
        }
    }

    return 0;
}
