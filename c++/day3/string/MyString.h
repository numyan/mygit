#ifndef MYSTRING_H_
#define MYSTRING_H_


//MyString str = "hello world";   MyString str("hello world")

class MyString{
private:
	char*		m_data;
public:
	//禁止隐士转化
	//explicit MyString(const char* _str);
	MyString(const char* _str);
	/*
		拷贝构造：一种特殊的构造函数
			用一个已经存在的对象去创建一个新的对象
		类中默认有一个拷贝构造函数,如果自定义了拷贝构造，那么默认的拷贝构造就会被覆盖.
		默认的拷贝构造的实现：把一个对象的非静态成员以值的形式赋值给另一个对象.

		int x = 10;
		int y = x;

		struct x{
			int x;
			int y;
		};

		struct x x1 = {3,4};
		struct x x2 = x1;   //3 4
		class Ex{
			int x;
			int y;
		};

		Ex e1(4,5);
		Ex e2 = e1;
		当一个类中存在指针成员时，大多数情况都需要重写拷贝构造.

		拷贝构造调用的条件：
			1 用一个对象初始化另一个对象
			2 在参数传递过程中，实际参数以值的形式传递给形式参数
			3 在一个函数中，以值的形式返回一个类的对象时


	
	*/


	//拷贝构造的声明
	MyString(const MyString& rhs);			//const 可选参数   &必选

	const char* data() const { return this->m_data; }
	~MyString();
};


#endif
