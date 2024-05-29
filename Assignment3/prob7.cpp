#include <iostream>
#include <vector>
using namespace std;

int countStoneToCapture(int x, int y, int color);
void PrintBoard();
void FlipStone(int x, int y, int color);
int EndGame(vector<vector<int>>& board);
int Winner(vector<vector<int>>& board);
vector<vector<int>> board(8, vector<int>(8, 0));

class Pos {
public:
	int x, y;
};

int main() {
	Pos pos;
	board[3][3] = 1; // 검은 돌(사람)
	board[3][4] = 2; // 흰 돌(컴퓨터)
	board[4][3] = 2;
	board[4][4] = 1;
	PrintBoard();
	bool turn = false;
	while (1) {
		if (EndGame(board) == 1) break;
		if (!turn) {
			cin >> pos.x >> pos.y;
			cout << endl;
			if (board[pos.x][pos.y] != 0) {
				cout << "현재 위치에 돌을 놓을 수 없습니다. 다시 입력하세요" << endl;
				continue;
			}
			FlipStone(pos.x, pos.y, 1);
			PrintBoard();
			cout << "===============(나)" << endl;
			turn = true;
		}
		else {
			int maxCnt = 0;
			Pos best;
			best.x = -1, best.y = -1;
			for(int i = 0; i < 8; i++)
				for (int j = 0; j < 8; j++) {
					if (board[i][j] != 0) continue;
					int cnt = countStoneToCapture(i, j, 2);
					if (cnt > maxCnt) {
						maxCnt = cnt;
						best.x = i;
						best.y = j;
					}
				}
			if (best.x != -1 && best.y != -1)
				FlipStone(best.x, best.y, 2);
			else break;
			PrintBoard();
			cout << "===============(상대)" << endl;
			turn = false;
		}
	}
	if (Winner(board) == 2)
		cout << "컴퓨터 승!" << endl;
	else if (Winner(board) == 1)
		cout << "사람 승!" << endl;
	else
		cout << "무승부!" << endl;
	return 0;
}

int countStoneToCapture(int x, int y, int color) {
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int d = 0; d < 8; d++) {
		int cnt = 0;
		int nx = x + dx[d];
		int ny = y + dy[d];

		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] != 0 && board[nx][ny] != color) {
			cnt++;
			nx += dx[d];
			ny += dy[d];
		}

	
		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == color && cnt > 0)
			return cnt;
	}
	return -1;
}

void PrintBoard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
}

int EndGame(vector<vector<int>>& board) {
	bool flag = false;
	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 8; j++)
			if (board[i][j] == 0) {
				flag = true;
				break;
			}
	if (!flag) return 1;
	return 0;
}

int Winner(vector<vector<int>>& board) {
	int cmp = 0, per = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 1) per++;
			else if (board[i][j] == 2) cmp++;
		}
	if (cmp > per) return 2;
	else if (cmp < per) return 1;
	else return 0;
}

void FlipStone(int x, int y, int color) {
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	board[x][y] = color;
	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		while (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] != 0 && board[nx][ny] != color) {
			nx += dx[d];
			ny += dy[d];
		}

		if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && board[nx][ny] == color) {
			int cx = x + dx[d];
			int cy = y + dy[d];
			while (cx != nx || cy != ny) {
				board[cx][cy] = color;
				cx += dx[d];
				cy += dy[d];
			}
		}
	}
}