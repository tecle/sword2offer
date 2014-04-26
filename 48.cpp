#include<iostream>
using namespace std;
/*定义一个不可一被继承的类*/


//方法1：将构造函数定义成私有函数,提供静态方法返回实例
class A{
	private:
		A(){}
		~A(){}
	public:
		void say(){cout<<"hello world!"<<endl;}
		static A* getInstance(){
			return new A;
		}
};

//方法2：使用辅助类实现
//模板编程还是不熟悉，需要加强
//通过声明友元类访问自己的私有成员函数
//后来继承自B的类是没有办法访问到辅助类的私有构造函数，因此继承失败
template <class T>class Helper{
friend T;
private:
	Helper(){};
	~Helper(){};
};
class B:virtual public Helper<B>{
public:
	B(){};
	~B(){};
	void say(){cout<<"hello world!"<<endl;}
};


//这里是没办法继承的
class C:public B{
public:
	C(){}
	~C(){}
}

int main(){
	A * a=A::getInstance();
	a->say();
	B b;
	b.say();
}
