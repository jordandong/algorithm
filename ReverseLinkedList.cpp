/*
 *Reverse a single LinkedList
 */

#include<iostream>
using namespace std;
struct LinkedListNode{
	int data;
	LinkedListNode* next;
};

LinkedListNode* ReverseLinkedList(LinkedListNode* head, LinkedListNode* &newhead){
	if(!head||!head->next){
		newhead=head;
		return head;
	}

	LinkedListNode* tmp = ReverseLinkedList(head->next, newhead);
	tmp->next = head;
	head->next=NULL;
	tmp=tmp->next;
	return tmp;
}

void ReverseLinkedListII(LinkedListNode* &head){
	LinkedListNode* prev=NULL;
	LinkedListNode* curr=head;
	while(head){
		curr=curr->next;
		head->next=prev;
		prev=head;
		head=curr;
	}
	head=prev;
}

void Delete(LinkedListNode* &root, int val){
	LinkedListNode* prev=NULL;
	LinkedListNode* curr=root;
	if(root->data==val){
		prev=root->next;
		delete root;
		root = prev;
	}
	else{
		while(curr&&curr->data!=val){
			prev=curr;
			curr=curr->next;
		}
		if(curr){
			curr=curr->next;
			delete prev->next;
			prev->next=curr;
		}
	}	
}

void printLinkedList(LinkedListNode* head){
	while(head){
		cout<<head->data<<endl;
		head=head->next;
	}
	cout<<endl;
}

int main(){
	LinkedListNode* head=NULL;
	LinkedListNode* tail=head;
	for(int i=0;i<10;i++){
		LinkedListNode *tmp=new LinkedListNode;
		tmp->data=i;
		tmp->next=NULL;
		if(!head){
			head=tmp;
			tail=head;
		}else{
			tail->next=tmp;
			tail=tail->next;
		}
	}
	printLinkedList(head);
	LinkedListNode* newhead=NULL;

	ReverseLinkedListII(head);
	printLinkedList(head);

	Delete(head, 3);
	printLinkedList(head);

	ReverseLinkedList(head, newhead);
	printLinkedList(newhead);	
	return 0;
}
