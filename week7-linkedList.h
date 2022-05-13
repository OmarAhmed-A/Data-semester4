/*


Mini-Task-(2):
Write a code that removes a node contianing the data specified by the user.
This node can be any node inside of the linked list 

Example1:

 h
[1]->[10]->[15]->[-1]->NULL

after ta call to removeAny(h, 15), the linked list should become

 h
[1]->[10]->[-1]->NULL


*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	Node* next;
};

Node* insertLast(Node* h, int item)
{
	if (h == NULL)	//Linked List is not yet created
	{
		h = (Node*)malloc(sizeof(Node));
		h->data = item;
		h->next = NULL;
	}
	else
	{
		Node* it = h;
		while (it->next != NULL)
			it = it->next;

		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->data = item;
		tmp->next = NULL;

		it->next = tmp;
	}

	return h;
}

Node* insertFirst(Node* h, int item)
{
	if (h == NULL)	//Linked List is not yet created
	{
		h = (Node*)malloc(sizeof(Node));
		h->data = item;
		h->next = NULL;
	}
	else
	{

		Node* tmp = (Node*)malloc(sizeof(Node));
		tmp->data = item;

		tmp->next = h;
		h = tmp;
	}

	return h;
}

Node* removeLast(Node* h, int* item)
{
	if (h == NULL)
		return NULL;

	if (h->next == NULL)
	{
		*item = h->data;
		free(h);
		h = NULL;
	}
	else
	{
		Node* it = h;
		while (it->next->next != NULL)
			it = it->next;

		*item = it->next->data;
		free(it->next);
		it->next = NULL;
	}
	return h;
}

Node* removeFirst(Node* h, int* item)
{
	if (h == NULL)
		return NULL;

	if (h->next == NULL)
	{
		*item = h->data;
		free(h);
		h = NULL;
	}
	else
	{
		Node* tmp = h->next;
		*item = h->data;
		free(h);
		h = tmp;
	}
	return h;
}


//Stack wrappers
Node* push(Node* h, int data)
{
	return insertFirst(h, data);
}

Node* pop(Node* h, int* data)
{
	return removeFirst(h, data);
}

Node* top(Node* h)
{
	return h;
}

//Queue wrappers
Node* enqueue(Node* h, int data) //enqueue is optimized in this case
{
	return insertFirst(h, data);
}

Node* dequeue(Node* h, int* data)	//performance of dequeue is lower than the enqueue in this case
{
	return removeLast(h, data);
}



// int main()
// {
// 	int d;

// 	Node* stack = NULL;
// 	stack = push(stack, 1);
// 	stack = push(stack, 2);
// 	stack = pop(stack, &d);
// 	stack = pop(stack, &d);



// 	Node* myLinkedList = NULL;
// 	myLinkedList = insertLast(myLinkedList, 10);
// 	myLinkedList = insertLast(myLinkedList, 20);
// 	myLinkedList = insertLast(myLinkedList, 30);
// 	myLinkedList = insertFirst(myLinkedList, 100);

// 	myLinkedList = removeFirst(myLinkedList, &d);
// 	myLinkedList = removeLast(myLinkedList, &d);
// 	myLinkedList = removeLast(myLinkedList, &d);
// 	myLinkedList = removeLast(myLinkedList, &d);


// 	return 0;
// }