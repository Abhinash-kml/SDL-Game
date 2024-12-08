#include "list.h"

list_t* create_list()
{
	list_t* new_list = (list_t*)malloc(sizeof(list_t));
	if (!new_list)
	{
		printf("Couldn't allocate memory for a list.\n");
		return NULL;
	}

	new_list->head = NULL;
	new_list->tail = NULL;
	new_list->count = 0;

	return new_list;
}

int insert_at_head(void* data, list_t* list)
{
	if (!list)
	{
		printf("The provided pointer to list is not valid\n");
		return 0;
	}

	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	if (!new_node)
	{
		printf("Couldn't allocate memory for a node of list.\n");
		return 0;
	}

	new_node->data = data;
	new_node->next = list->head;
	new_node->prev = NULL;

	if (list->head)
		list->head->prev = new_node;
	else
		list->tail = new_node;		// First node in the list

	list->head = new_node;
	list->count++;
	
	return 1;
}

int insert_at_tail(void* data, list_t* list)
{
	if (!list)
	{
		printf("The provided pointer to list is not valid\n");
		return 0;
	}

	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	if (!new_node)
	{
		printf("Couldn't allocate memory for a node of list\n");
		return 0;
	}

	new_node->data = data;
	new_node->prev = list->tail;
	new_node->next = NULL;

	if (list->tail)
		list->tail->next = new_node;
	else
		list->head = new_node;		// First node in the list

	list->tail = new_node;
	list->count++;
	return 1;
}

void* remove_at_head(list_t* list)
{
	if (!list || !list->head)
	{
		printf("The provided pointer to list is not valid\n");
		return NULL;
	}

	node_t* old_head = list->head;
	void* data = list->head->data;

	list->head = old_head->next;
	if (list->head)
		list->head->prev = NULL;
	else
		list->tail = NULL;

	free(old_head);
	list->count--;

	return data;
}

void* remove_at_tail(list_t* list)
{
	if (!list || !list->tail)
	{
		printf("The provided pointer to list is not valid\n");
		return NULL;
	}

	node_t* old_tail = list->tail;
	void* data = old_tail->data;

	list->tail = old_tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	else
		list->head = NULL;

	free(old_tail);
	list->count--;
	return data;
}

void destroy_list(list_t* list)
{
	if (!list)
	{
		printf("Cannot destroy list pointed by invalid pointer\n");
		return;
	}

	node_t* current = list->head;
	while (current) 
	{
		node_t* next = current->next;
		free(current->data);	// Free the current node's data
		free(current);			// Free the current node
		current = next;
	}

	free(list);
}
