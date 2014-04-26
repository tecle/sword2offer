#include"myhead.h"

int addTwoNum(int a,int b){
	int tmp,sum;
	do{
		sum=a^b;
		tmp=(a&b)<<1;
		a=sum;
		b=tmp;
	}while(tmp);
	return sum;
}

int main(){
	int x,y;
	while(cin>>x>>y){
		cout<<addTwoNum(x,y)<<endl;
	}
}
