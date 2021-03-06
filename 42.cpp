#include "myhead.h"
/*
deal翻转英语字符串，以空格区分
deal2字符串左旋n位
*/

void reverse(string &str,int head,int tail){
	while(head < tail){
		std::swap(str[head],str[tail]);
		head++;
		tail--;
	}
}
void deal(string &str,int left){
	int len=str.size();
	if(left<0 ){
		cout<<"error!"<<endl;return;
	}
	if(left==0){
		cout<<str<<endl;return;
	}
	left=left%len;
	reverse(str,0,left-1);
	reverse(str,left,len-1);
	reverse(str,0,len-1);
	cout<<str<<endl;
}
void deal(string &str){
	int len=str.size();
	int i=0,j=len-1;
	
	reverse(str,0,len-1);
	
	int pre=0;
	i=0;
	while(i<len){
		if(str[i] == ' ' ){
			reverse(str,pre,i-1);
			//find next char that not blank
			while(str[i]==' ')
				i++;
			pre=i;
		}else if(i==len-1){
			reverse(str,pre,i);
			break;
		}else
			i++;
	}
	
	cout<<str<<endl;
}

int main(){
	string str="I am a student.";
	cout<<"Original string:"<<str<<endl;
	cout<<"choose deal way,1 or 2:"<<endl;
	int way;
	while(cin>>way){
		if(way==1)
			deal(str);
		else if(way==2)
			deal(str,3);
	}
}

