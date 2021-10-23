#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"


Node* createNode(void* value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

List* createList() {
	List* newList = (List*)malloc(sizeof(List));
	newList->head = NULL;
	newList->tail = NULL;
	newList->length = 0;
	return newList;
}


void push_front(List* list, void* value) {
	Node* node = createNode(value);
	if (list->length == 0) {
		list->head = node;
		list->tail = node;
		list->length++;
		return;
	}
	node->prev = NULL;
	list->head->prev = node;
	node->next = list->head;
	list->head = node;
	list->length++;
}

void push_back(List* list, void* value) {
	Node* node = createNode(value);
	if (list->length == 0) {
		list->head = node;
		list->tail = node;
		list->length++;
		return;
	}
	node->next = NULL;
	node->prev = list->tail;
	list->tail->next = node;
	list->tail = node;
	list->length++;
}

void addNodeAfter(List* list, void* value, int index) {
	if (index >= list->length) return;
	if (index == LAST) return push_back(list, value);
	Node* newNode = createNode(value);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = list->head;
	for (int id = 0; id < index; id++) {
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp;
	temp->next->prev = newNode;
	temp->next = newNode;
	list->length++;
}

void addNodeBefore(List* list, void* value, int index) {
	if (index >= list->length) return;
	if (index == FIRST) return push_front(list, value);
	Node* newNode = createNode(value);
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = FIRST_ELEMENT;
	for (int id = 0; id < index; id++) {
		temp = temp->next;
	}
	newNode->next = temp;
	newNode->prev = temp->prev->next;
	temp->prev->next = newNode;
	temp->prev = newNode;
	list->length++;
}

void printNodes(Node* node) {
	if (node == NULL) {
		printf("\n");
		return;
	}
	while (node != NULL) {
		printf("%d\n", node->value);
		node = node->next;
	}
	printf("\n");
}

void printList(List* list) {
	if (FIRST_ELEMENT == NULL) return;
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = list->head;
	while (temp != NULL) {
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}

void deleteNode(List* list, int index) {
	Node* temp = (Node*)malloc(sizeof(Node));
	if (list->length == 0) return;
	if (index > list->length) return;
	temp = list->head;

	if (index == FIRST) {
		temp->next->prev = NULL;
		list->head = temp->next;
		list->length--;
		return free(temp);
	}
	if (index == LAST) {
		temp = list->tail;
		temp->prev->next = NULL;
		list->tail = temp->prev;
		list->length--;
		return free(temp);
	}

	for (int id = 0; id < index; id++) {
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	list->length--;
	free(temp);
}

void deleteList(List* list) {
	Node* current = list->head;
	while (current != NULL) {
		Node* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}