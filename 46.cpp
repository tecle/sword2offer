#include "myhead.h"

/*使用多种巧妙方法解决1+2+3+...+n*/

class A{
public:
	static int n;
	static int sum;
	A(){A::sum+=(++A::n);}
	~A(){}
	static void init(){A::n=0;A::sum=0;}
	static int getResult(){return sum;}
};
int A::n=0;
int A::sum=0;

//利用构造函数和静态变量配合数组元素的声明来实现1+2+..+n
void way1(){
	A::init();
	A *a=new A[100];
	cout<<"way1:"<<A::getResult()<<endl;
}

class B;
B* arrayb[2];

class B{
public:
	virtual int helper(int n){return 0;}
	B(){}
	~B(){}
};

class C:public B{
public:
	int sum;
	C():sum(0){}
	virtual int helper(int n){return n+arrayb[!!n]->helper(n-1);}
};
//利用递归的方法来解决，递归的结束条件采用数组选择方式
void way2(){
	arrayb[0]=new B;
	arrayb[1]=new C;
	cout<<"way2:"<<arrayb[1]->helper(100)<<endl;
}

typedef int(*Fun)(int);
Fun funs[2];
int f1(int n){
	return n+funs[!!n](n-1);
}
int f0(int n){
	return 0;
}
//和方法二类似，不过使用了函数指针来实现递归的结束
void way3(){
	funs[0]=f0;
	funs[1]=f1;
	cout<<"sway3:"<<funs[1](100)<<endl;
}

template <unsigned int n> struct Sum_4{
	enum Value{N=Sum_4<n-1>::N+n};
};

template<>struct Sum_4<1>{
	enum Value{N=1};
};

void way4(){
	cout<<"way4:"<<Sum_4<100>::N<<endl;
}

int main(){
	way1();
	way2();
	way3();
	way4();
}


