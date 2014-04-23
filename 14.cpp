#include "myhead.h"
/*调整数组顺序使得符合某个条件的数在不符合条件的数的前面*/


/*首位指针向中间移动*/
//judge是指能放在前面的一个数的判断
void deal(vector<int> &v,bool (*judge)(int) ){
	int i=0,j=v.size()-1;
	while(i<j){
		while(i<j && !judge(v[j]))
			j--;
		while(i<j && judge(v[i]))
			i++;
		std::swap(v[i],v[j]);
	}
}

//为真的放左边，为假的放右边
bool test(int i){
	if(i>=0)
		return true;
	return false;
}

int main(){
	vector<int> v={1,-2,3,-4,-5,5,9,0,1,-4};
	deal(v,test);
	for(auto &ele:v)
		cout<<ele<<" ";
	
}
