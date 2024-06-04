#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int year, month, day;
public:
    Date();
    Date(int y, int m, int d);
    Date(string date_string);

    bool operator<(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;
    void print(ostream& out) const;
};
