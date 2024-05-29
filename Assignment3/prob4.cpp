#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string checkOmok(vector<vector<int>>& board) {
    const int N = board.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - 5; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] &&
                board[i][j] == board[i][j + 4]) {
                return (board[i][j] == 1) ? "Black" : "White";
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - 5; j++) {
            if (board[j][i] != 0 && board[j][i] == board[j + 1][i] &&
                board[j][i] == board[j + 2][i] && board[j][i] == board[j + 3][i] &&
                board[j][i] == board[j + 4][i]) {
                return (board[j][i] == 1) ? "Black" : "White";
            }
        }
    }

    for (int i = 0; i <= N - 5; i++) {
        for (int j = 0; j <= N - 5; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] &&
                board[i][j] == board[i + 4][j + 4]) {
                return (board[i][j] == 1) ? "Black" : "White";
            }
        }
    }

    for (int i = 0; i <= N - 5; i++) {
        for (int j = N - 1; j >= 4; j--) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] &&
                board[i][j] == board[i + 4][j - 4]) {
                return (board[i][j] == 1) ? "Black" : "White";
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) return "Not Finished";
        }
    }
}

int main() {
    ifstream infile("board.txt");
    int N;
    infile >> N;

    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            infile >> board[i][j];
        }
    }
    infile.close();
    string result = checkOmok(board);
    cout << result << endl;
    return 0;
}
