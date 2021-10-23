#pragma once
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define FIRST_ELEMENT list->head
#define LAST_ELEMENT list->tail
#define FIRST 0
#define LAST list->length - 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
	void* value;
	struct Node_s* next;
	struct Node_s* prev;
} Node;

typedef struct List_s {
	int length;
	Node* head;
	Node* tail;
} List;


Node* createNode(void* value);

List* createList();

void push_front(List* list, void* value);

void push_back(List* list, void* value);

void addNodeAfter(List* list, void* value, int index);

void addNodeBefore(List* list, void* value, int index);

void printNodes(Node* node);

void printList(List* list);

void deleteNode(List* list, int index);

void deleteList(List* list);
