#include "myhead.h"
/*
数组中只出现一次的数字
数组里除了两个数字之外，其他数字都出现了两次。
*/
void deal(vector<int> &nums){
	int len=nums.size();
	int ans=0;
	for(int &num:nums){
		ans=(ans^num);
	}
	if(ans==0)
		return;
	
	int pos=1;
	while(pos){	
		if(ans & pos)
			break;
		pos = pos << 1;
	}
	int head=-1,i=0;
	while(i<len){
		if( nums[i] & pos ){
			head++;
			std::swap(nums[i],nums[head]);
		}
		i++;
	}
	//0...head , head+1...len
	int ans1=0,ans2=0;
	for(i=0;i<=head;i++)
		ans1=(ans1 ^ nums[i]);
	
	for(i=head+1;i<len;i++)
		ans2=(ans2 ^ nums[i]);
	
	cout<<ans1<<","<<ans2<<endl;
	
}

int main(){
	vector<int> v={2,4,3,6,3,2,5,5,4,1};
	deal(v);
}
