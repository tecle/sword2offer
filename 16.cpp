#include"myhead.h"

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode *reverse(ListNode * head){
	if(!head || !head->next)
		return head;
	ListNode* itr=head,*pre=NULL,*tmp;
	while(itr){
		tmp=itr->next;
		itr->next=pre;
		pre=itr;
		itr=tmp;
	}
	return pre;
}

int main(){
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head=reverse(head);
	while(head){
		cout<<head->val;
		head=head->next;
	}
	cout<<endl;
}
