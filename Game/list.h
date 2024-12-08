#pragma once

#include "common.h"

typedef struct Node
{
	void* data;
	node_t* next;
	node_t* prev;
} node_t;

typedef struct List
{
	node_t* head;
	node_t* tail;
	size_t count;
} list_t;

list_t* create_list();
int insert_at_head(void* data, list_t* list);
int insert_at_tail(void* data, list_t* list);
int remove_at_head(void* data, list_t* list);
int remove_at_tail(void* data, list_t* list);
