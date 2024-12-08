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

	// Check if list is empty
	if (list->head == NULL && list->tail == NULL)
	{
		list->head = new_node;
		list->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		list->count += 1;

		return 1;
	}

	// List is not empty
	new_node->next = list->head;
	list->head->prev = new_node;
	new_node->prev = NULL;
	list->head = new_node;
	list->count += 1;
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

	// Check if list is empty
	if (list->head == NULL && list->tail == NULL)
	{
		free(new_node);
		return insert_at_head(data, list);
	}

	// List is not empty
	list->tail->next = new_node;
	new_node->prev = list->tail;
	list->tail = new_node;
	list->count += 1;
	return 1;
}

int remove_at_head(void* data, list_t* list)
{
	if (!list)
	{
		printf("The provided pointer to list is not valid\n");
		return 0;
	}

	// Check if list is empty
	if (list->head == NULL && list->tail == NULL)
	{
		printf("Cannot remove anything from an empty list\n");
		return 0;
	}

	// List is not empty
	node_t* old_head = list->head;
	node_t* second_node = list->head->next;
	second_node->prev = NULL;
	list->head = second_node;
	list->count -= 1;
	free(old_head);
	return 1;
}

int remove_at_tail(void* data, list_t* list)
{
	if (!list)
	{
		printf("The provided pointer to list is not valid\n");
		return 0;
	}

	// Check if list is empty
	if (list->head == NULL && list->tail == NULL)
	{
		printf("Cannot remove anything from an empty list\n");
		return 0;
	}

	// List is not empty
	node_t* old_tail = list->tail;
	node_t* second_last_node = old_tail->prev;
	second_last_node->next = NULL;
	list->tail = second_last_node;
	list->count -= 1;
	free(old_tail);
	return 1;
}
