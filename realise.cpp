#include "head.h"

Field_P::Field_P() {
    _p = 0;
    _data = 0;
}

Field_P::Field_P(const size_t newP, const long newData) {
    _p = newP;
    _data = newData % newP;
}
Field_P::Field_P(const Field_P& newObj) {
    _p = newObj._p;
    _data = newObj._data;
}

Field_P::~Field_P() {
    std::cout<<"Destroy" << _p << " " << _data << std::endl;
    _p = 0;
    _data = 0;
}



Field_P& Field_P::operator=(const Field_P& newNum){
    Field_P tmp(newNum);
    return tmp;
}

Field_P& Field_P::operator=(const long num){
    Field_P tmp;
    if(_p != 0){
        _data = num % _p;
    }
    else{
        Field_P tmp(num > 0? num * 1: num *(-1) + 1, num);
        return tmp;
    }
    return *this;
}

Field_P& Field_P::operator[](const size_t base) {
    _p = base;
    _data = 0;
    return *this;
}

Field_P Field_P::operator+(const Field_P& a) const {
//    Field_P tmp;
//    std::cout << "hereq" << std::endl;
    if(a._p != _p){
        //Field_P tmp(_p, (a._data + _data) % _p);
        //return  tmp;
//        tmp[_p] = (a._data + _data) % _p;
        std::cout << "here" << std::endl;
        Field_P error_obj(0, 0);
        return error_obj;
    }
    else{
        Field_P tmp(_p, (a._data + _data) % _p);
        std::cout << "hereq" << std::endl;
        return tmp;
    }
}
    //Field_P error_obj(0, 0);
    //return error_obj;


Field_P Field_P::operator+(const long a) const {
    Field_P result(_p, (a % _p + _data % _p) % _p);
    return result;
}

Field_P Field_P::operator*(const Field_P & a) const {
    if(a._p != _p){
        Field_P error_obj(0, 0);
        //std::cout << "error" << std::endl;
        return error_obj;
    }
    long tmp_data = (a._data * _data) % _p;
    Field_P tmp(_p, tmp_data);
    return tmp;
}

Field_P Field_P::operator*(const long a) const {
    Field_P tmp(_p, (_data * (a % _p)) % _p);
    return tmp;
}

//Field_P& Field_P::operator-(Field_P & a) const {
//    Field_P tmp(_p, _data - (a._data % _p));
//    return tmp;
//}
//
//Field_P& Field_P::operator-(long a) const {
//    Field_P tmp(_p, _data - (a % _p));
//    return tmp;
//}
