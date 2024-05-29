#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Line {
public:
	int x1, y1, x2, y2;
};

bool intersect(const Line& a, const Line& b) {
	if (a.x1 == a.x2 && b.y1 == b.y2) {
		if (a.x1 >= min(b.x1, b.x2) && a.x1 <= max(b.x1, b.x2) && min(a.y1, a.y2) <= b.y1 && max(a.y1, a.y2) >= b.y1)
			return true;
	}
	else if (a.y1 == a.y2 && b.x1 == b.x2) {
		if (b.x1 >= min(a.x1, a.x2) && b.x1 <= max(a.x1, a.x2) && min(b.y1, b.y2) <= a.y1 && max(b.y1, b.y2) >= a.y1)
			return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector<Line> lines(n);
	vector<int> intersection_x, intersection_y;
	for (int i = 0; i < n; i++) 
		cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (intersect(lines[i], lines[j])) {
				int x, y;
				if (lines[i].x1 == lines[i].x2) {
					x = lines[i].x1;
					y = lines[j].y1;
				}
				else {
					x = lines[j].x1;
					y = lines[i].y1;
				}
				intersection_x.push_back(x);
				intersection_y.push_back(y);
			}
		}
	}
	int j = 0;
	for (int i = intersection_x.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (intersection_x[j] > intersection_x[j + 1]) {
				swap(intersection_x[j], intersection_x[j + 1]);
				swap(intersection_y[j], intersection_y[j + 1]);
			}
			else if (intersection_x[j] == intersection_x[j + 1]) {
				if (intersection_y[j] > intersection_y[j + 1]) {
					swap(intersection_x[j], intersection_x[j + 1]);
					swap(intersection_y[j], intersection_y[j + 1]);
				}
			}
		}
	}

	for (int i = 0; i < intersection_x.size(); i++)	
		cout << "[" << intersection_x[i] << ", " << intersection_y[i] << "]" << endl;
	return 0;
}
