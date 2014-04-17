#include "myhead.h"
/*
输入递增排序的数组和一个数字s，找出数组中和为s的两个数对
*/
void deal(int num[],int n,int tar){
	int i=0,j=n-1;
	while(i<j){
		if( num[i]+num[j] > tar )
			j--;
		else if(num[i]+num[j] < tar)
			i++;
		else{
			cout<<num[i]<<"+"<<num[j]<<"="<<tar<<endl;
			i++;
		}
	}
}

int main(){
	int A[]={1,2,4,5,6,7,8,11,12,13,14,15,16,17};
	int target=14;
	deal(A,14,target);

}
