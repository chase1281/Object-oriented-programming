#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void IsValid(vector<vector<char>>& grid, int x, int y, int n, const vector<string>& dictionary);
bool BinarySearch(const vector<string>& dictionary, const string& res);

vector<string> result;
int main() {
	ifstream infile("puzzle.txt");
	int n;
	infile >> n;
	vector<vector<char>> grid(n, vector<char>(n));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			infile >> grid[i][j];
	infile.close();

	vector<string> dictionary;
	ifstream infile2("dictionary.txt");
	string str;
	while (infile2 >> str)
		dictionary.push_back(str);
	infile2.close();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			IsValid(grid, i, j, n, dictionary);

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		if (i == 0 || result[i] != result[i - 1])
			cout << result[i] << endl;
	return 0;
}

void IsValid(vector<vector<char>>& grid, int x, int y, int n, const vector<string>& dictionary) {
	int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	string res;
	for (int i = 0; i < 8; i++) {	
		int nx = x;
		int ny = y;
		while (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			res += grid[nx][ny];
			if (BinarySearch(dictionary, res)) {
				result.push_back(res);
			}
			nx += dx[i];
			ny += dy[i];
		}
		res.clear();
	}
}

bool BinarySearch(const vector<string>& dictionary, const string& res) {
	int left = 0, right = dictionary.size()-1;
	while (left <= right) {
		int mid = left + (right-left) / 2;
		if (dictionary[mid] == res)
			return true;
		else if (dictionary[mid] > res) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	return false;
}