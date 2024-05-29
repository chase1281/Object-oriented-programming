#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

string removespace(const string& str) {
	string res;
	bool prev = false;
	for (auto c : str) {
		if (!isspace(c)) {
			res += c;
			prev = false;
		}
		else {
			if (!prev) {
				res += ' ';
				prev = true;
			}
		}
	}
	res.erase(res.find_last_not_of(" \t") + 1);
	res.erase(0, res.find_first_not_of(" \t"));
	return res;
}

int main() {
	ifstream infile("table.txt");
	ofstream outfile("output.txt");
	int row, col;
	infile >> row >> col;
	vector<vector<string>> matrix(row, vector<string>(col));

	string line;
	getline(infile, line);
	for (int i = 0; i < row; i++) {
		getline(infile, line);
		int start = 0;
		for (int j = 0; j < col; j++) {
			int idx = line.find("&", start);
			if (idx != string::npos) {
				matrix[i][j] = removespace(line.substr(start, idx - start));
				start = idx + 1;
			}
			else
				matrix[i][j] = removespace(line.substr(start));
		}
	}

	vector<int> maxColWidth(col, 0);
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			maxColWidth[j] = max(maxColWidth[j], static_cast<int>(matrix[i][j].size()));
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			outfile << matrix[i][j];
			int spacesToAdd = maxColWidth[j] - matrix[i][j].size() + 1;
			for (int k = 0; k < spacesToAdd; k++) {
				outfile << ' ';
			}
		}
		outfile << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}