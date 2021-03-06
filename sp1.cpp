#include"myhead.h"
/*二维数组的左旋*/

void reverse(int *num,int head,int tail,int rows,int cols){
	int row,col;
	while(head < tail){
		//std::swap(num[head/cols][head - head/cols*row],num[tail/cols][tail - tail/cols*tail]);
		std::swap(*(num+head),*(num+tail));
		head++;
		tail--;
	}
}

int leftRotate(int* num,int rows,int cols,int left){
	if(left>=rows*cols)
		left = left%(rows*cols);
	reverse(num,0,left-1,rows,cols);
	reverse(num,left,rows*cols-1,rows,cols);
	reverse(num,0,rows*cols-1,rows,cols);
}

int main(){
	int A[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
	leftRotate(&A[0][0],4,5,99);
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}

}


