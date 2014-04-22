#include"myhead.h"
/*把数组排成最小的数*/
bool cmp(string s1,string s2){
	string tmp1=s1+s2;
	string tmp2=s2+s1;
	int len=tmp1.size();
	for(int i=0;i<len;i++){
		if(tmp1[i] >tmp2[i])
			return false;
		else if(tmp1[i]<tmp2[i])
			return true;
	}
	return true;
}

int main(){
	vector<string> nums={"32","3","321"};
	sort(nums.begin(),nums.end(),cmp);
	for(auto &ele:nums)
		cout<<ele;
	cout<<endl;
}
