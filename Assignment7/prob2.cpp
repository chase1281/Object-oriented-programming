#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject() {}
	GameObject(int startX, int startY, int distance) {
		this->x = startX; this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};
	
	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) {
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else
			return false;
	}

	bool out_of_range(int newX, int newY) {
		return (newX >= 0 && newX < 10 && newY >= 0 && newY < 20);
	}
};

class Human : public GameObject {
private:
	char dir;
public:
	Human() {};
	Human(int startX, int startY) : GameObject(startX, startY, 1) {}
	Human(int startX, int startY, char d) : GameObject(startX, startY, 1), dir(d) {}
	void move() override {
		int newX = x, newY = y;
		if (dir == 'a') newY -= distance; // left
		else if (dir == 's') newX += distance; // down
		else if (dir == 'd') newX -= distance; // up
		else if (dir == 'f') newY += distance; // right

		if (out_of_range(newX, newY)) {
			x = newX;
			y = newY;
		}
	}

	char getShape() override { return 'H'; }
	void setDirection(char d) { dir = d; }
};

class Monster : public GameObject {
public:
	Monster() {}
	Monster(int startX, int startY) : GameObject(startX, startY, 2) {}
	void move() override {
		int newX = x, newY = y;
		int pos = rand() % 4;
		if (pos == 0) newY -= distance; // left
		else if (pos == 1) newX += distance; // down
		else if (pos == 2) newX -= distance; // up
		else if (pos == 3) newY += distance; // right

		if (out_of_range(newX, newY)) {
			x = newX;
			y = newY;
		}
	}

	char getShape() override { return 'M'; }
};

class Food : public GameObject {
private:
	int count;
public:
	Food() {}
	Food(int startX, int startY) : GameObject(startX, startY, 1), count(1) {}
	void move() override {
		if (count <= 3) {
			count++;
			return;
		}
		int newX = x, newY = y;
		int pos = rand() % 4;
		if (pos == 0) newY -= distance; // left
		else if (pos == 1) newX += distance; // down
		else if (pos == 2) newX -= distance; // up
		else if (pos == 3) newY += distance; // right

		if (out_of_range(newX, newY)) {
			x = newX;
			y = newY;
		}

		count++;
		if (count == 6) count = 1;
	}

	char getShape() override { return '@'; }
};

class Game {
private:
	Human* human;
	Monster* monster;
	Food* food;
	char board[10][20];

	void clearBoard() { // 초기화
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				board[i][j] = '-';
			}
		}
	}

	void placeBoard() { // 초기값 설정
		board[human->getX()][human->getY()] = human->getShape();
		board[monster->getX()][monster->getY()] = monster->getShape();
		board[food->getX()][food->getY()] = food->getShape();
	}

	void printBoard() { // 출력
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
public:
	Game() {
		srand(unsigned int(time(NULL)));
		human = new Human(rand() % 10, rand() % 20);
		monster = new Monster(rand() % 10, rand() % 20);
		food = new Food(rand() % 10, rand() % 20);

		char directions[4] = { 'a', 's', 'd', 'f' };
		char randomDir = directions[rand() % 4];
		human->setDirection(randomDir);
	}
	~Game() {
		delete human;
		delete monster;
		delete food;
	}
	void play() {
		char command;
		while (true) {
			clearBoard();
			placeBoard();
			printBoard();

			if (human->collide(food) == true) {
				cout << "Human is Winner!!" << endl;
				break;
			}

			if (monster->collide(food) == true || human->collide(monster) == true) {
				cout << "Human is Loser!!" << endl;
				break;
			}

			cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
			cin >> command;
			cout << endl;
			human->setDirection(command);
			human->move();
			monster->move();
			food->move();
		}
	}
};

int main() {
	cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl << endl;
	Game game;
	game.play();
	return 0;
}