#include"myhead.h"
/*两个递增链表的有序合并*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int v):val(v),next(NULL){}
};

ListNode *combine(ListNode *head0,ListNode *head1){
	if(!head0)
		return head1;
	if(!head1)
		return head0;
	ListNode *head=new ListNode(1);
	ListNode *last=head;
	while(head0&&head1){
		if(head0->val < head1->val){
			last->next=head0;
			head0=head0->next;
		}else{
			last->next=head1;
			head1=head1->next;
		}
		last=last->next;
	}
	if(head0){
		last->next=head0;
	}
	if(head1){
		last->next=head1;
	}
	last=head;
	head=head->next;
	delete last;
	return head;
}
int main(){
	ListNode* h0=new ListNode(2);
	h0->next=new ListNode(4);
	h0->next->next=new ListNode(5);
	ListNode* h1=new ListNode(1);
	h1->next=new ListNode(3);
	ListNode* ans=combine(h0,h1);
	while(ans){
		cout<<ans->val<<" ";
		ans=ans->next;
	}
	cout<<endl;
}


