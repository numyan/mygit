#include "MyString.h"
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>

MyString::MyString(const char* _str)
{
	if(0 == _str){
		this->m_data = new char[1]();
		this->m_data[0] = '\0';
	}else{
		int len = strlen(_str);
		this->m_data = new char[len + 1]();
		strcpy(this->m_data, _str);
		this->m_data[len] = '\0';
	}

	cout << "MyString" << endl;
}

MyString::~MyString()
{
	if(this->m_data != 0)
		delete [] this->m_data;
	cout << "~MyString" << endl;
}

MyString::MyString(const MyString& rhs)
{
	cout << "copy" << endl;
	//根据rhs申请空间
	int len = strlen(rhs.m_data);
	this->m_data = new char[len + 1]();
	strcpy(this->m_data, rhs.m_data);
	this->m_data[len] = '\0';
}
