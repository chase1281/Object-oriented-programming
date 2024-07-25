#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
using namespace std;

class Point {
private:
	double x, y;
public:
	Point() = default;
	Point(double a, double b) : x(a), y(b) {}

	double dist(Point other) {
		return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
	}

	double distToLine(Point p1, Point p2) {
		if (p1.y > p2.y || p1.x > p2.x) swap(p1, p2);
		double d = this->dist(p1);
		if (p1.x == p2.x) {
			for (int ny = p1.y; ny <= p2.y; ny++) {
				if (d > this->dist(Point(p1.x, ny))) {
					d = this->dist(Point(p1.x, ny));
				}
			}
		}
		else {
			for (int nx = p1.x; nx <= p2.x; nx++) {
				if (d > this->dist(Point(nx, p1.y))) {
					d = this->dist(Point(nx, p1.y));
				}
			}
		}
		return d;
	}

	double get_X() { return x; }
	double get_Y() { return y; }
};

class Circle {
private:
	Point cen;
	double radi;
public:
	Circle() = default;
	Circle(Point a, double r) : cen(a), radi(r) {}
	Circle(double x, double y, double r) : cen(x, y), radi(r) {}

	Point get_cen() { return cen; }
	double get_radi() { return radi; }

	double area() {
		return radi * radi * 3.141592;
	}

	bool intersecting(Circle cir) {
		return !(cir.get_radi() + radi < cen.dist(cir.get_cen()));
	}

	void print(ostream& out) {
		out << "C ";
		out << cen.get_X() << " " << cen.get_Y() << " " << radi;
	}
};

class Rect {
private:
	Point lu, rl;
public:
	Rect() = default;
	Rect(Point a, Point b): lu(a), rl(b) {}
	Rect(int x1, int x2, int y1, int y2) : lu(x1, y1), rl(x2, y2) {} 

	Point get_lu() { return lu; }
	Point get_rl() { return rl; }

	double area() {
		return (rl.get_Y() - lu.get_Y()) * (rl.get_X() - lu.get_X());
	}

	bool intersecting(Circle cir) { 
		Point ll(rl.get_X(), lu.get_Y());
		Point ru(lu.get_X(), rl.get_Y());
		//사각형 꼭짓점4개 중 하나라도 원 내부에 있거나, 모두 내부에 있거나, 
		//모두 밖에 있지만 원의 중심이 사각형 내부에 있거나, 모두 밖에 있지만 한 변이 교차할때 4가지 경우 검사필요
		if (lu.dist(cir.get_cen()) <= cir.get_radi() || ll.dist(cir.get_cen()) <= cir.get_radi()
			|| ru.dist(cir.get_cen()) <= cir.get_radi() || rl.dist(cir.get_cen()) <= cir.get_radi()) return true;
		if (lu.dist(cir.get_cen()) <= cir.get_radi() && ll.dist(cir.get_cen()) <= cir.get_radi()
			&& ru.dist(cir.get_cen()) <= cir.get_radi() && rl.dist(cir.get_cen()) <= cir.get_radi()) return true;
		else if (lu.get_X() <= cir.get_cen().get_X() && cir.get_cen().get_X() <= rl.get_X()
			&& lu.get_Y() <= cir.get_cen().get_Y() && cir.get_cen().get_Y() <= rl.get_Y() ) {
			return true;
		}
		else{
			vector<Point> points = { ll,rl,ru, lu };
			for (int i = 0; i < points.size(); i++) {
				if (cir.get_cen().distToLine(points[i], points[(i+1)%4]) <= cir.get_radi()) return true;
			}
		}
		return false;
	}

	void print(ostream& out) {
		out << "R ";
		out << lu.get_X() << " " << lu.get_Y() << " " << rl.get_X() << " " << rl.get_Y();
	}
};

class Shape {
private:
	vector<pair<char, vector<int>>> shape;
public:
	Shape() = default;

	vector<pair<char, vector<int>>>& get_Shape() { return shape; }

	void addRect(Rect r);
	void addCircle(Circle c);
};

void Shape::addRect(Rect r) {
	pair<char, vector<int>> s;
	s.first = 'R';
	s.second.push_back(r.get_lu().get_X()); s.second.push_back(r.get_rl().get_X());
	s.second.push_back(r.get_lu().get_Y()); s.second.push_back(r.get_rl().get_Y());
	shape.push_back(s);
}

void Shape::addCircle(Circle c) {
	pair<char, vector<int>> s;
	s.first = 'C';
	s.second.push_back(c.get_cen().get_X()); s.second.push_back(c.get_cen().get_Y());
	s.second.push_back(c.get_radi());
	shape.push_back(s);
}

void intersected(Shape& s, Circle& c) {
	for (auto it = s.get_Shape().begin(); it != s.get_Shape().end();) {//비교 원과 교차하지 않는 도형들 벡터에서 삭제
		if (it->first == 'C') {
			Circle cir(it->second[0], it->second[1], it->second[2]);
			if (!cir.intersecting(c)) {
				it = s.get_Shape().erase(it);
			}
			else it++;
		}
		else {
			Rect r(it->second[0], it->second[1], it->second[2], it->second[3]);
			if (!r.intersecting(c)) {
				it = s.get_Shape().erase(it);
			}
			else it++;
		}
	} 
}

bool compareArea(pair<char, vector<int>>& a, pair<char, vector<int>>& b) {
	if (a.first == 'C' && b.first == 'C') {
		Circle c1(a.second[0], a.second[1], a.second[2]);
		Circle c2(b.second[0], b.second[1], b.second[2]);
		return c1.area() < c2.area();
	}
	else if (a.first == 'C' && b.first == 'R') {
		Circle c(a.second[0], a.second[1], a.second[2]);
		Rect r(b.second[0], b.second[1], b.second[2], b.second[3]);
		return c.area() < r.area();
	}
	else if (a.first == 'R' && b.first == 'C') {
		Rect r(a.second[0], a.second[1], a.second[2], a.second[3]);
		Circle c(b.second[0], b.second[1], b.second[2]);
		return r.area() < c.area();
	}
	else {
		Rect r1(a.second[0],a.second[1], a.second[2], a.second[3]);
		Rect r2(b.second[0], b.second[1], b.second[2], b.second[3]);
		return r1.area() < r2.area();
	}
}

void get_input(Shape& s) {
	ifstream infile("input1.txt");
	int n;
	int x1, x2, y1, y2;
	int x, y, radi;
	char type;
	infile >> n;
	for (int i = 0; i < n; i++) {
		infile >> type;
		if (type == 'R') {
			infile >> x1 >> x2 >> y1 >> y2;
			Rect r(x1, x2, y1, y2);
			s.addRect(r);	
		}
		else if(type == 'C') {
			infile >> x >> y >> radi;
			Circle c(x, y, radi);
			s.addCircle(c);
		}
	}
	infile >> x >> y >> radi;
	Circle c(x, y, radi); // 비교 기준
	infile.close();

	intersected(s, c);
	sort(s.get_Shape().begin(), s.get_Shape().end(), compareArea);

	for (auto& z : s.get_Shape()) {
		cout << z.first << " ";
		for (auto& v : z.second)
			cout << v << " ";
		cout << endl;
	}
}

int main() {
	Shape s;
	get_input(s);
	return 0;
}