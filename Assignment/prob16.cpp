#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double per1() {
    int cnt = 0;
    for (int i = 0; i < 1000000; i++) {
        int flag = 0;
        for (int j = 0; j < 6; j++) {
            if (rand() % 6 + 1 == 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            cnt++;
    }
    return (double)cnt / 1000000;
}

double per2() {
    int cnt = 0;
    for (int i = 0; i < 1000000; i++) {
        int flag = 0;
        for (int j = 0; j < 12; j++) 
            if (rand() % 6 + 1 == 1) 
                flag++;
        if (flag >= 2) 
            cnt++;
    }
    return (double)cnt / 1000000;
}

int main() {
    srand((unsigned int)time(NULL));
    cout << per1() << endl;
    cout << per2() << endl;
    return 0;
}