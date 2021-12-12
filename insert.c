/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:38:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 14:26:05 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_bucket	*allocate_bucket(void)
{
	t_bucket	*bucket;

	bucket = (t_bucket *)malloc(sizeof(t_bucket));
	return (bucket);
}

void	handle_collision(t_hashtable *table,
		unsigned long index, t_ht_item *item)
{
	t_bucket	*head;

	printf("Entered handle_collision()\n");
	head = table->buckets[index];
	if (head == NULL)
	{
        // We need to create the list
		head = allocate_bucket();
		head->item = item;
		head->next = NULL;
		table->buckets[index] = head;
		return ;
	}
	else
	{
        // Insert to the list
		table->buckets[index] = bucket_insert(head, item);
		return ;
	}
}

t_bucket	*bucket_insert(t_bucket *list, t_ht_item *item)
{
	if (!list)
	{
		t_bucket	*head = allocate_bucket();
		head->item = item;
		head->next = NULL;
		list = head;
		return (list);
	}
	else if (list->next == NULL)
	{
		t_bucket	*node = allocate_bucket();
		node->item = item;
		node->next = NULL;
		list->next = node;
		return (list);
	}
	t_bucket	*temp = list;
	// This below seems BAD
	while (temp->next)
	{
		temp = temp->next;
	}
	t_bucket	*node = allocate_bucket();
	node->item = item;
	node->next = NULL;
	temp->next = node;
	return (list);
}

void	ht_insert(t_hashtable *table, char *key, char *value)
{
	t_ht_item	*item;
	t_ht_item	*current_item;
	int			index;

	item = create_item(key, value);
	index = hash_function(key);
	current_item = table->items[index];
	if (current_item == NULL)
	{
		if (table->count == table->size)
		{
			ft_putstr("Insert Error: Hash Table is full\n");
			free_item(item);
			return ;
		}
		table->items[index] = item;
		table->count++;
	}
	else
	{
		if (ft_strncmp(current_item->key, key, ft_strlen(key)) == 0)
		{
			free(table->items[index]->value);
			table->items[index]->value = value;
			return ;
		}
		else
		{
			handle_collision(table, index, item);
			return ;
		}
	}
}
