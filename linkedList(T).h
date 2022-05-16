/*


Mini-Task-(2):
Write a code that removes a Node<T> contianing the data specified by the user.
This Node<T> can be any Node<T> inside of the linked list

Example1:

 h
[1]->[10]->[15]->[-1]->NULL

after ta call to removeAny(h, 15), the linked list should become

 h
[1]->[10]->[-1]->NULL


*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
template <typename T>
struct Node
{
	T data;
	Node<T> *next;
};
template <typename T>
Node<T> *insertLast(Node<T> *h, T item)
{
	if (h == NULL) // Linked List is not yet created
	{
		h = (Node<T> *)malloc(sizeof(Node<T>));
		h->data = item;
		h->next = NULL;
	}
	else
	{
		Node<T> *it = h;
		while (it->next != NULL)
			it = it->next;

		Node<T> *tmp = (Node<T> *)malloc(sizeof(Node<T>));
		tmp->data = item;
		tmp->next = NULL;

		it->next = tmp;
	}

	return h;
}

template <typename T>
Node<T> *insertFirst(Node<T> *h, T item)
{
	if (h == NULL) // Linked List is not yet created
	{
		h = (Node<T> *)malloc(sizeof(Node<T>));
		h->data = item;
		h->next = NULL;
	}
	else
	{

		Node<T> *tmp = (Node<T> *)malloc(sizeof(Node<T>));
		tmp->data = item;

		tmp->next = h;
		h = tmp;
	}

	return h;
}

template <typename T>
Node<T> *removeLast(Node<T> *h, T *item)
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
		Node<T> *it = h;
		while (it->next->next != NULL)
			it = it->next;

		*item = it->next->data;
		free(it->next);
		it->next = NULL;
	}
	return h;
}

template <typename T>
Node<T> *removeFirst(Node<T> *h, T *item)
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
		Node<T> *tmp = h->next;
		*item = h->data;
		free(h);
		h = tmp;
	}
	return h;
}

template <typename T>
// Stack wrappers
Node<T> *push(Node<T> *h, T data)
{
	return insertFirst(h, data);
}

template <typename T>
Node<T> *pop(Node<T> *h, T *data)
{
	return removeFirst(h, data);
}

template <typename T>
Node<T> *peek(Node<T> *h)
{
	return h;
}

template <typename T>
// Queue wrappers
Node<T> *enqueue(Node<T> *h, T data) // enqueue is optimized in this case
{
	return insertFirst(h, data);
}

template <typename T>
Node<T> *dequeue(Node<T> *h, T *data) // performance of dequeue is lower than the enqueue in this case
{
	return removeLast(h, data);
}

// int main()
// {
// 	int d;

// 	Node<T>* stack = NULL;
// 	stack = push(stack, 1);
// 	stack = push(stack, 2);
// 	stack = pop(stack, &d);
// 	stack = pop(stack, &d);

// 	Node<T>* myLinkedList = NULL;
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