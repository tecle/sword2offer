#include"myhead.h"
#include<stack>
/*栈的压入、弹出序列*/
bool isRightOrder(int *push,int *pop,int size){
	int i=0,j=0;
	stack<int> helper;
	if(size <= 1)
		return true;
	while(j<size){
		while(helper.empty() || helper.top()!=pop[j]){
			if(i==size)
				break;
			helper.push(push[i++]);
		}
		if(helper.top()!=pop[j])
			return false;
		j++;
		helper.pop();
	}
	return true;
}

int main(){
	int a[]={1,2,3,4,5};
	int b[]={4,5,3,2,1};
	cout<<isRightOrder(a,b,5)<<endl;
}
