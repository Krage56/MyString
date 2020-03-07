#pragma once
#include <iostream>
#include <cmath>
class Field_P{
public:
    Field_P();
    Field_P(const Field_P&);
    Field_P(const size_t, const long);
    ~Field_P();

    Field_P& operator[](const size_t);
    Field_P& operator=(const Field_P&);
    Field_P& operator=(const long);
    Field_P operator+(const Field_P&)const;
    Field_P operator+(const long)const;
    Field_P operator-(const Field_P&)const;
    Field_P operator-(const long)const;
    Field_P operator*(const Field_P&)const;
    Field_P operator*(const long)const;

    friend std::ostream& operator<< (std::ostream& stream, Field_P& ex) {
        stream << "Number: " << ex._data << ", base: " << ex._p;
        return stream;
    }

private:
    size_t _p;
    long _data;

};
