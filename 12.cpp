#include"myhead.h"
#include<stdexcept>

void printNum(vector<char> &nm){
	bool start=false;
	for(int i=nm.size()-1;i>=0;i--){
		if(start || nm[i]!='0'){
			cout<<nm[i];
			start=true;
		}
	}
	if(start)
		cout<<endl;
}

/*打印1到最大的n位数*/
bool add(vector<char> &num){
	int flag=1,pos=0,len=num.size();
	while(flag){
		if(num[len-1]=='9' && pos==len-1)
			return false;
		if(num[pos] == '9'){
			flag=1;
			num[pos]='0';
		}else{
			flag=0;
			num[pos]++;
		}
		pos++;
	}
	return true;
}
/*递归解法
这个解法会将0也打印出来
*/
void deal(vector<char> &num,int pos){
	//到达最深处，打印
	if(pos<0){
		printNum(num);
		return;
	}
	for(int i=0;i<10;i++){
		num[pos]=i+'0';
		deal(num,pos-1);
	}
	
}

void deal1(vector<char> &nm){
	while(add(nm)){
			printNum(nm);
			
		}
}
int main(){
	int num;
	while(cin>>num){
		if(num <= 0)
			throw out_of_range("bad input!");
		vector<char> nm(num,'0');
		deal(nm,num-1);		
	}
}
