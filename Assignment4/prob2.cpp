#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Point {
public:
    int x, y;
    Point() = default;
    Point(int a, int b) : x(a), y(b) {}
};

class Rect {
private:
    Point lu, rl;
public:
    Rect() = default;
    Rect(int x1, int x2, int y1, int y2) : lu(x1, y1), rl(x2, y2) {}

    Point getLu() const { return lu; }
    Point getRl() const { return rl; }
};

void get_input(istream& infile, vector<Rect>& rects) {
    int x1, x2, y1, y2, n;
    infile >> n;
    while (n--) {
        infile >> x1 >> x2 >> y1 >> y2;
        rects.push_back(Rect(x1, x2, y1, y2));
    }
}

pair<Point, int> find_smallest_circle(const vector<Rect>& rects) {
    Point min_cen;
    int min_radi = -1;

    for (const auto& rect : rects) {
        Point lu = rect.getLu();
        Point rl = rect.getRl();

        int dx = rl.x - lu.x;
        int dy = rl.y - lu.y;

        int cx = lu.x + dx / 2;
        int cy = lu.y + dy / 2;

        int radi = ceil(sqrt(dx * dx + dy * dy) / 2);

        if (min_radi == -1 || cx - radi < min_cen.x - min_radi || cx + radi > min_cen.x + min_radi ||
            cy - radi < min_cen.y - min_radi || cy + radi > min_cen.y + min_radi) {
            min_cen = { cx, cy };
            min_radi = radi;
        }
    }

    return { min_cen, min_radi };
}

int main() {
    vector<Rect> rects;
    ifstream infile("input2.txt");
    get_input(infile, rects);
    infile.close();

    pair<Point, int> result = find_smallest_circle(rects);

    Point cen = result.first;
    int radius = result.second;

    cout << "중점: " << cen.x << ", " << cen.y << endl;
    cout << "반지름: " << radius << endl;

    return 0;
}
