#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
Node* next;
    // Node()
	// {
	// 	next = NULL;
	// }
};

Node* insertLast(Node *h,int d){
  if(h == NULL)
  {
    h=(Node*)malloc(sizeof(Node));
    h->data=d;
    h->next=NULL;
  }
  else{
    Node* it=h;
    while(it->next!=NULL)
      it=it->next;
    Node* tmp=(Node*)malloc(sizeof(Node));
    tmp->data=d;
    tmp->next=NULL;
    it->next =tmp;
  }
  return h;
}


int main() {
  Node* head= NULL;
 head= insertLast(head,10);
 head= insertLast(head,15);
 head= insertLast(head,125);

  
  return 0;
}