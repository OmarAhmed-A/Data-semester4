#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
Node* next;

    Node()
	{
		next = NULL;
	}
};
struct Node3{
int data;
Node* next1;
Node* next2;
Node* next3;

    Node3()
	{
		next1 = NULL;
        next2 = NULL;
        next3 = NULL;
	}
};



int main() {
  Node3* start= NULL;
  Node* two= NULL;
  Node* three= NULL;
  Node* four= NULL;
  Node* end= NULL;
    start->data=10;
    start->next1 =two;
    two->data = 20;

    start->next2=three;
    three->data = 30;

    start->next3=four;
    four->data = 40;

    end->data=100;
    two->next=end;
    three->next=end;
    four->next=end;

  
  return 0;
}