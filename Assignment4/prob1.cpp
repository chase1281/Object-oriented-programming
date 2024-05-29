#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class Point {
public:
    int x, y;
    Point() = default;
    Point(int a, int b) : x(a), y(b) {}
};

class Rect; // 전방 선언

class Circle {
private:
    Point cen;
    int radi;
public:
    Circle() = default;
    Circle(int x, int y, int r) : cen(x, y), radi(r) {}

    double CArea() const {
        return radi * radi * 3.14;
    }

    double dist(const Circle& other) const {
        return sqrt((cen.x - other.cen.x) * (cen.x - other.cen.x) + (cen.y - other.cen.y) * (cen.y - other.cen.y));
    }

    bool intersect_cir(const Circle& other) const {
        if (radi + other.radi < dist(other))
            return false;
        else
            return true;
    }

    bool intersect_Rect(const Rect& rect) const;

    bool inner_Rect(const Rect& rect) const;

    // cen에 접근할 수 있는 public 메서드 추가
    Point getCen() const { return cen; }

    // radi에 접근할 수 있는 public 메서드 추가
    int getRadi() const { return radi; }
};

class Rect {
private:
    Point lu, rl;
    friend class Circle;
public:
    Rect() = default;
    Rect(int x1, int x2, int y1, int y2) : lu(x1, y1), rl(x2, y2) {}

    int RArea() const {
        return (rl.x - lu.x) * (rl.y - lu.y);
    }

    Point getLu() const { return lu; }
    Point getRl() const { return rl; }
};

// Circle 클래스의 멤버 함수 정의
bool Circle::intersect_Rect(const Rect& rect) const {
    double left = rect.lu.y;
    double right = rect.rl.y;
    double top = rect.lu.x;
    double bottom = rect.rl.x;

    // 원의 중심과 직사각형의 네 변 사이의 거리 계산
    double distLeft = cen.y - left;
    double distRight = right - cen.y;
    double distTop = cen.x - top;
    double distBottom = bottom - cen.x;

    // 직사각형의 네 변과 원의 중심 사이의 거리가 원의 반지름보다 작으면 교차
    bool intersectLeft = (distLeft <= radi);
    bool intersectRight = (distRight <= radi);
    bool intersectTop = (distTop <= radi);
    bool intersectBottom = (distBottom <= radi);

    // 직사각형의 네 변 중 하나라도 원과 교차하는 경우 교차로 판단
    if (intersectLeft || intersectRight || intersectTop || intersectBottom)
        return true;

    // 직사각형의 네 꼭지점 중 하나가 원 안에 있는 경우 교차로 판단
    if ((cen.y >= left && cen.y <= right) && (cen.x >= top && cen.x <= bottom))
        return true;

    // 위의 조건에 해당하지 않으면 교차하지 않음
    return false;
}

bool Circle::inner_Rect(const Rect& rect) const {
    return rect.lu.y > cen.y - radi &&
        rect.rl.y < cen.y + radi &&
        rect.lu.x > cen.x - radi &&
        rect.rl.x < cen.x + radi;
}

void get_input(istream& infile, vector<pair<Circle, Rect>>& vec) {
    int x1, x2, y1, y2, n, r;
    char ch;
    infile >> n;
    while (n--) {
        infile >> ch;
        if (ch == 'R') {
            infile >> x1 >> x2 >> y1 >> y2;
            Rect rect(x1, x2, y1, y2);
            vec.push_back({ Circle(), rect });
        }
        else if (ch == 'C') {
            infile >> x1 >> y1 >> r;
            Circle circle(x1, y1, r);
            vec.push_back({ circle, Rect() });
        }
    }
    infile >> x1 >> y1 >> r;
    Circle circle(x1, y1, r);
    vec.push_back({ circle, Rect() });
}

bool sortByArea(const pair<Circle, Rect>& a, const pair<Circle, Rect>& b) {
    double area_a = (a.first.intersect_cir(b.first) || a.first.inner_Rect(b.second)) ? max(a.first.CArea(), double(b.second.RArea())) : 0;
    double area_b = (b.first.intersect_cir(a.first) || b.first.inner_Rect(a.second)) ? max(b.first.CArea(), double(a.second.RArea())) : 0;
    return area_a > area_b;
}

int main() {
    vector<pair<Circle, Rect>> vec;
    ifstream infile("input1.txt");
    get_input(infile, vec);
    infile.close();

    sort(vec.begin(), vec.end(), sortByArea);

    for (const auto& shape : vec) {
        char shape_type = (shape.first.intersect_cir(vec.back().first) || shape.first.inner_Rect(vec.back().second)) ? 'C' : 'R';
        if (shape_type == 'C') {
            Point cen = shape.first.getCen();
            int radi = shape.first.getRadi();
            cout << "C " << cen.x << " " << cen.y << " " << radi << endl;
        }
        else {
            cout << "R " << shape.second.getLu().x << " " << shape.second.getLu().y << " " << shape.second.getRl().x << " " << shape.second.getRl().y << endl;
        }
    }

    return 0;
}
