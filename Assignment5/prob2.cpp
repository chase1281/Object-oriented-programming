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
        return radi + other.radi >= dist(other);
    }

    bool intersect_Rect(const Rect& rect) const;

    bool inner_Rect(const Rect& rect) const;

    Point getCen() const { return cen; }
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

bool Circle::intersect_Rect(const Rect& rect) const {
    double left = rect.lu.y;
    double right = rect.rl.y;
    double top = rect.lu.x;
    double bottom = rect.rl.x;

    double distLeft = cen.y - left;
    double distRight = right - cen.y;
    double distTop = cen.x - top;
    double distBottom = bottom - cen.x;

    bool intersectLeft = (distLeft <= radi);
    bool intersectRight = (distRight <= radi);
    bool intersectTop = (distTop <= radi);
    bool intersectBottom = (distBottom <= radi);

    if (intersectLeft || intersectRight || intersectTop || intersectBottom)
        return true;

    if ((cen.y >= left && cen.y <= right) && (cen.x >= top && cen.x <= bottom))
        return true;

    return false;
}

bool Circle::inner_Rect(const Rect& rect) const {
    return rect.lu.y > cen.y - radi &&
        rect.rl.y < cen.y + radi &&
        rect.lu.x > cen.x - radi &&
        rect.rl.x < cen.x + radi;
}

void get_input(istream& infile, vector<pair<Circle*, Rect*>>& vec, Circle*& additionalCircle) {
    int x1, x2, y1, y2, n, r;
    char ch;
    infile >> n;
    while (n--) {
        infile >> ch;
        if (ch == 'R') {
            infile >> x1 >> x2 >> y1 >> y2;
            Rect* rect = new Rect(x1, x2, y1, y2);
            vec.push_back({ nullptr, rect });
        }
        else if (ch == 'C') {
            infile >> x1 >> y1 >> r;
            Circle* circle = new Circle(x1, y1, r);
            vec.push_back({ circle, nullptr });
        }
    }
    infile >> x1 >> y1 >> r;
    additionalCircle = new Circle(x1, y1, r);
}

bool intersects(const pair<Circle*, Rect*>& shape, const Circle* additionalCircle) {
    if (shape.first != nullptr) {
        return shape.first->intersect_cir(*additionalCircle);
    }
    if (shape.second != nullptr) {
        return additionalCircle->intersect_Rect(*shape.second) || additionalCircle->inner_Rect(*shape.second);
    }
    return false;
}

double area(const pair<Circle*, Rect*>& shape) {
    if (shape.first != nullptr) {
        return shape.first->CArea();
    }
    if (shape.second != nullptr) {
        return shape.second->RArea();
    }
    return 0;
}

int main() {
    vector<pair<Circle*, Rect*>> vec;
    ifstream infile("input1.txt");
    Circle* additionalCircle = nullptr;
    get_input(infile, vec, additionalCircle);
    infile.close();

    vector<pair<Circle*, Rect*>> intersectingShapes;
    for (const auto& shape : vec) {
        if (intersects(shape, additionalCircle)) {
            intersectingShapes.push_back(shape);
        }
    }

    sort(intersectingShapes.begin(), intersectingShapes.end(), [](const pair<Circle*, Rect*>& a, const pair<Circle*, Rect*>& b) {
        return area(a) > area(b);
    });

    for (const auto& shape : intersectingShapes) {
        if (shape.first != nullptr) {
            Point cen = shape.first->getCen();
            int radi = shape.first->getRadi();
            cout << "C " << cen.x << " " << cen.y << " " << radi << endl;
        }
        else if (shape.second != nullptr) {
            Point lu = shape.second->getLu();
            Point rl = shape.second->getRl();
            cout << "R " << lu.x << " " << lu.y << " " << rl.x << " " << rl.y << endl;
        }
    }

    // 메모리 해제
    delete additionalCircle;
    for (auto& shape : vec) {
        delete shape.first;
        delete shape.second;
    }

    return 0;
}
