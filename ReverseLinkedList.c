/*
 *Reverse a single LinkedList
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode{
	int data;
	struct LinkedListNode* next;
} LinkedListNode;

LinkedListNode* ReverseLinkedList(LinkedListNode* head, LinkedListNode** newhead){
	if(!head||!head->next){
		*newhead=head;
		return head;
	}

	LinkedListNode* tmp = ReverseLinkedList(head->next, newhead);
	tmp->next = head;
	head->next=NULL;
	tmp=tmp->next;
	return tmp;
}

void ReverseLinkedListII(LinkedListNode** head){
	LinkedListNode* prev=NULL;
	LinkedListNode* curr=*head;
	while(*head){
		curr=curr->next;
		(*head)->next=prev;
		prev=*head;
		*head=curr;
	}
	*head=prev;
}

void DeleteII(LinkedListNode** root, int val){
	LinkedListNode* prev=NULL;
	LinkedListNode** curr=root;
	if((*root)->data==val){
		prev=(*root)->next;
		free(*root);
		*root = prev;
	}
	else{
		while(*curr&&(*curr)->data!=val){
			curr=&((*curr)->next);
			if((*curr)->next)
				prev=(*curr)->next;
			else
				prev=NULL;
		}
		if(*curr){
			free(*curr);
			(*curr)=prev;
		}
	}	
}


void Delete(LinkedListNode** root, int val){
	LinkedListNode* prev=NULL;
	LinkedListNode* curr=*root;
	if((*root)->data==val){
		prev=(*root)->next;
		free(*root);
		*root = prev;
	}
	else{
		while(curr&&curr->data!=val){
			prev=curr;
			curr=curr->next;
		}
		if(curr){
			curr=curr->next;
			free(prev->next);
			prev->next=curr;
		}
	}	
}

void printLinkedList(LinkedListNode* head){
	while(head){
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main(){
	LinkedListNode* head=NULL;
	LinkedListNode* tail=head;
	int i=0;
	for(i=0;i<10;i++){
		LinkedListNode *tmp=malloc(sizeof(LinkedListNode));
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
	DeleteII(&head, 0);
	printLinkedList(head);
	Delete(&head, 7);
	printLinkedList(head);
	ReverseLinkedListII(&head);
	printLinkedList(head);
	LinkedListNode* newhead=NULL;
	ReverseLinkedList(head, &newhead);
	printLinkedList(newhead);
	

	return 0;
}
