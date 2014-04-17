#include"myhead.h"
/*过滤空格，替换成20%*/

//O(n)，但是创建了个新的字符串
int _deal(char *s){
	char *ptr=s;
	int cnt=0;
	while(*ptr!='\0'){
		if(*ptr == ' ')
			cnt++;
		ptr++;
	}
	char *newstr=new char[strlen(s)+cnt*2+1];
	int i=0,j=0;
	while(s[i] != '\0'){
		if(s[i]==' '){
			newstr[j++]='2';
			newstr[j++]='0';
			newstr[j++]='%';
		}else{
			newstr[j++]=s[i];
		}
		i++;
	}
	cout<<newstr<<endl;
}

//不创建新的字符串
int deal(char *s){
	char *ptr=s;
	int cnt=0,len=0;
	while(*ptr !='\0'){
		if(*ptr == ' ')
			cnt++;
		ptr++;
		len++;
	}
	
	int i=len-1,j=len+cnt*2;
	s[j--]='\0';
	//在原始长度的基础上，往后面移动 cnt *2的格子
	while(i>=0){
		if(s[i]==' '){
			s[j--]='%';
			s[j--]='0';
			s[j--]='2';
		}else
			s[j--]=s[i];
		i--;
	}
	cout<<s<<endl;
	
}
int main(){

	char p[]={'a',' ','b',' ',' ','c','d'};
	cout<<"original:"<<p<<endl;
	_deal(p);
	char *p1=new char(14);
	for(int i=0;i<=7;i++)
		p1[i]=p[i];
	deal(p1);
	
	
}
