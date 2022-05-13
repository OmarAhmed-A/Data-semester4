#include "week7-linkedList.h"


Node* removeData(Node*head, int key)
{
	Node* temp=head,*prev;
	if(temp->data==key)
	{
		head=temp->next;
		free(temp);
		return head;
	}
	else
	while (temp->data!=key&&temp!=NULL)
	{
		prev = temp;
		temp=temp->next;
	}
	if(temp==NULL)
	printf("not found\n");
	else if(temp->data==key)
	{
		prev->next = temp->next;
		free(temp);
	}
	return head;
}
void print(Node *head) {
    Node *current_node = head;
   	while ( current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
	printf("\n");
}

int main()
{
	int d;

	Node* stack = NULL;
	stack = push(stack, 1);
	stack = push(stack, 2);
	stack = pop(stack, &d);
	stack = pop(stack, &d);



	Node* myLinkedList = NULL;
	myLinkedList = insertLast(myLinkedList, 75);
	myLinkedList = insertLast(myLinkedList, 20);
	myLinkedList = insertLast(myLinkedList, 30);
 	myLinkedList = insertFirst(myLinkedList, 125);
	print(myLinkedList);
	myLinkedList = removeData(myLinkedList, 75);
	print(myLinkedList);
	myLinkedList = removeFirst(myLinkedList, &d);

	myLinkedList = removeLast(myLinkedList, &d);
	myLinkedList = removeLast(myLinkedList, &d);
	myLinkedList = removeLast(myLinkedList, &d);


	return 0;
}