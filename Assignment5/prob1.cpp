#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderedVecInt {
private:
	int capacity = 0, nowsize = 0;
	int* arr = nullptr;

	void resize() {
		if (capacity == 0)
			capacity = 1;
		else
			capacity *= 2;
		int* newArr = new int[capacity];
		for (int i = 0; i < nowsize; i++)
			newArr[i] = arr[i];
		delete[]arr;
		arr = newArr;
	}

public:
	OrderedVecInt() = default;
	~OrderedVecInt() {
		delete[]arr;
	}

	int size() const{
		return nowsize;
	}

	void insert(int k) {
		if (capacity == nowsize)
			resize();
		int i;
		for (i = nowsize-1; (i >= 0 && arr[i] > k); i--) {
			arr[i+1] = arr[i];
		}
		arr[i + 1] = k;
		nowsize++;
	}

	bool remove_by_index(int index) {
		if (index > nowsize) return false;
		for (int i = index; i < nowsize - 1; i++)
			arr[i] = arr[i + 1];
		nowsize--;
		return true;
	}

	bool remove_by_val(int value) {
		for (int i = 0; i < nowsize; i++) {
			if (arr[i] == value) {
				remove_by_index(i);
				return true;
			}
		}
		return false;
	}

	int operator[](int index) const {
		return arr[index];
	}

	int& operator[](int index){
		return arr[index];
	}
};

int main() {
	srand((unsigned int)time(NULL));
	int n, k;
	OrderedVecInt vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k = rand() % 1000;
		vec.insert(k);
	}
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	if (vec.remove_by_val(vec[2]))
		cout << "Remove done" << endl;
	else
		cout << "Remove failed" << endl;
	if (vec.remove_by_index(4))
		cout << "RemoveIndex done" << endl;
	else
		cout << "RemoveIndex failed" << endl;
	for (int i = 0; i < vec.size(); i++)
		vec[i] -= 10;
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}