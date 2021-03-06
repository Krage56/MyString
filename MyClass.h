#pragma once

#include <iostream>

using std::swap;

class MyString
{
public:
	MyString();										//����������� �� ���������
	MyString(const MyString &string);				//����������� ����������� [MyString copyString(string);]
	MyString(const char* string);					//����������� c ���������� [MyString copyString(string);]

	MyString& operator= (const MyString &string);	//�������� ������������ ������������
	MyString& operator= (const char * string);		//�������� ������������ ������������

	MyString operator+ (const MyString &string) const;			//��������
	MyString operator+ (const char * string) const;		//��������

	MyString& operator+= (MyString& string);		//�������� � ������������
	MyString& operator+= (const char * string);		//�������� � ������������

	bool	operator== (MyString& string) const;			//��������� �����
	bool	operator== (const char* string) const;		//��������� �����

	MyString	reverse();							//�������� ������
	size_t	size() const;								//������
	bool		isEmpty();							//��������, ������ �� ������


	friend std::ostream& operator<< (std::ostream& stream, const MyString &string) {
		stream << string._data;
		return stream;
	}

	friend std::istream& operator >> (std::istream& stream, const MyString &string) {
		//��������� ���
		return stream;
	}

	~MyString();									//����������
protected:
    MyString cat(const MyString& first) const;
    MyString& mutableCat(const MyString& first);
private:
	char *			_data;
	unsigned int	_size;
};

