#include"myhead.h"
#include<stack>
#include<cassert>
/*使用模板编程实现的最小栈*/
template <typename T> class MinStack{
private:
	stack<T> A;
	stack<T> B;
public:
	MinStack(){}
	~MinStack(){}
	T min(){
		assert(!B.empty());
		return B.top();
	}
	T top(){
		assert(!A.empty());
		return A.top();
	}
	void pop(){
		assert(!B.empty() && !A.empty());
		B.pop();
		A.pop();
	}
	void push(T v,bool (*cmp)(T &a,T &b)){
		A.push(v);
		if(B.empty || cmp(B.top(),v))
			B.push(v);
		else
			B.push(B.top());
	}
	void push(T v);
};

//在外部实现模板类的内部代码，注意MinStack后面的<T>不可缺少
template <typename T> void MinStack<T>::push(T v){
		A.push(v);
		if(B.empty() || B.top()>v)
			B.push(v);
		else
			B.push(B.top());
	}

int main(){
	MinStack<int> ms;
	//ms.pop();
	ms.push(2);
	ms.push(3);
	ms.push(4);
	cout<<ms.min()<<endl;
}
