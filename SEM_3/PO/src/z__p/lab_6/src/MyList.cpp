#include <MyList.h>
#include <MyStr.h>
#include <iostream>

void init(MyList *list) {
	list->head = NULL;
}

void append(MyList* list, const char *data) { 
	Node *createdNode = new Node;
	createdNode->data = mycopy(data);
	createdNode->next = NULL;

	Node *lastNode = last(list);

	if (lastNode == NULL) {
		list->head = createdNode;
	}
	else { 
		lastNode->next = createdNode;
	}
}

bool isEmpty(const MyList *list) { 
	return list->head == NULL;
}

void print(const MyList *list) {
	if (isEmpty(list))
		return;

	Node *current = list->head;

	while(current != NULL) { 
		std::cout << "<" << current->data << "> ";
		current = current->next;
	}

	std::cout << std::endl;
}

Node *last(const MyList *list) { 
	if (isEmpty(list)) 
		return NULL;
	
	Node *curr = list->head;

	while(curr->next != NULL)
		curr = curr->next;

	return curr;
}

void clearNode(Node *node) { 
	delete []node->data;
	delete node;
}

void clear(MyList *list) {

	if (isEmpty(list))
		return;

	Node *curr = list -> head;
	Node *next = list -> head;
	while (curr != NULL) { 
		next = curr -> next;
		clearNode(curr);
		curr = next;
	}

	list->head = NULL;
}

void removeFirst(MyList *list) {
	if (isEmpty(list))
		return;

	Node *curr = list->head;
	Node *next = curr->next;

	clearNode(curr);
	list->head = next;
}
