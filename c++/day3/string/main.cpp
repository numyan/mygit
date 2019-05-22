#include "MyString.h"
#include <iostream>
using namespace std;

void func(MyString s)
{
	cout << "s: " << s.data() << endl;
}

MyString bar()
{
	MyString s3("yes");
	return s3;

}

int main(int argc, char **argv)
{
	MyString s("hello");			//构造函数
	//MyString s  = "hello";
	cout << s.data() << endl;

	MyString s1(s);				//拷贝构造函数
	cout << s1.data() << endl;

	func(s1);
	bar();


	int z = 10;
	int y = z;


	return 0;
}
