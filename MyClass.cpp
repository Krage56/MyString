#include "MyClass.h"

#include <cstring>
#include <iostream>


MyString::MyString(){
	_data = new char[1];
	_data[0] = '\0';
	_size = 0;
}

MyString::MyString(const MyString& copy) {
	this->_size = copy._size;
	_data = new char[this->_size + 1];
	strcpy(this->_data, copy._data);
}

MyString::MyString(const char* str) {
	this->_size = strlen(str);
	this->_data = new char[_size + 1];
	strcpy(this->_data, str);
}

size_t MyString::size() const {
	return _size;
}

// MyString a("Hello");
MyString MyString::cat(const MyString& first) const {
	MyString result;
	result._size = this->_size + first._size;
	if (result._data) {
		delete[] result._data;
	}
	result._data = new char[result._size + 1];
	strcat(result._data, this->_data);
	strcat(result._data, first._data);

	return result;
}

MyString& MyString::mutableCat(const MyString& first) {
	char* buf = new char[this->_size + first._size + 1];
	if (this->_data) {
		strcpy(buf, this->_data);
		delete[] this->_data;
	}
	strcat(buf, first._data);
	this->_data = buf;
	this->_size = this->_size + first._size;

	return *this;
}

MyString MyString::operator+(const MyString& string) const {
	return this->cat(string);
}

MyString MyString::operator+ (const char * string) const{
    MyString new_str = string;
    return this->cat(new_str);
}

MyString& MyString::operator= (const MyString &string) {
	//std::cout << "Copy = operator" << std::endl;
	MyString buf(string);
	_size = buf._size;
	swap(_data, buf._data);

	/* Не реюзая код конструктора копирования */
	/*
	delete[] _data;
	_size = string._size;
	_data = new char[_size + 1];
	strcpy(_data, string._data);
	*/

	return *this;
}

MyString& MyString::operator= (const char * string) {
	/* Добавить вариант с использованием конструктора копирования */

	//std:: << "Copy = operator for cstring" << std::endl;
	delete[] _data;
	_size = strlen(string);
	_data = new char[_size + 1];
	strcpy(_data, string);
	return *this;
}


MyString& MyString::operator+= (MyString& string){
    mutableCat(string);
    return *this;
}

MyString& MyString::operator+= (const char * string){
    MyString tmp_str = string;
    mutableCat(string);
    return *this;
}


MyString::~MyString(){
	if (_data) {
		delete[] _data;
	}
	_size = 0;
}

bool MyString::operator==(MyString& string) const{
    return strcmp(_data, string._data) ? false : true;
}

bool MyString::operator==(const char* string) const{
    return strcmp(_data, string) ? false : true;
}

MyString MyString::reverse(){
    MyString result;
    result._size = _size;
    if(result._data){
        delete []result._data;
    }
    result._data = new char[_size + 1];
    result._data[_size] = '\0';
    for(int i = 0; i < _size; ++i){
        result._data[_size - i - 1] = _data[i];
    }
    return result;
}


bool MyString::isEmpty(){
    const char* str = "";
    return strcmp(this->_data, str)? false:true;
}

//void MyString::print() const {
//	std::cout << this->_data << std::endl;
//}

