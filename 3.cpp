#include"myhead.h"
/*二维有序数组的查找*/

bool deal(int *a,int rows,int cols,int tar){
	int num;
	int i=0,j=cols-1;
	while(j>=0 && i<rows){
		num=*(a+i*cols+j);
		if(num < tar)
			i++;
		else if(num > tar)
			j--;
		else{
			cout<<i<<","<<j<<endl;
			return true;
			
		}
	}
	cout<<"Not Found!"<<endl;
	return false;

}

int main(){
	int a[4][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	//这里传递的是数组的首地址
	deal(&a[0][0],4,4,7);

}
