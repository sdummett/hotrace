/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:38:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 21:25:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	handle_collision(t_hashtable *table,
		unsigned long index, t_ht_item *item)
{
	t_bucket	**head;

	head = &table->buckets[index];
	if (*head == NULL)
	{
		*head = allocate_bucket();
		(*head)->item = item;
		(*head)->next = NULL;
		table->buckets[index] = *head;
		return ;
	}
	else
	{
		bucket_insert(head, item);
		return ;
	}
}

t_bucket	**bucket_insert(t_bucket **list, t_ht_item *item)
{
	t_bucket	*temp;

	if (!*list)
	{
		*list = init_bucket(allocate_bucket(), item);
		return (list);
	}
	else if ((*list)->next == NULL)
	{
		(*list)->next = init_bucket(allocate_bucket(), item);
		return (list);
	}
	temp = *list;
	*list = init_bucket(allocate_bucket(), item);
	(*list)->next = temp;
	return (list);
}

void	handle_case_1(t_hashtable *table, t_ht_item *item, unsigned long index)
{
	if (table->count == table->size)
	{
		free_item(item);
		return ;
	}
	table->items[index] = item;
	table->count++;
}

void	ht_insert(t_hashtable *table, char *key, char *value)
{
	t_ht_item		*item;
	t_ht_item		*current_item;
	unsigned long	index;

	item = create_item(key, value);
	index = hash_function(key);
	current_item = table->items[index];
	if (current_item == NULL)
	{
		handle_case_1(table, item, index);
	}
	else
	{
		if (ft_strncmp(current_item->key, key, ft_strlen(key)) == 0)
		{
			free_item(current_item);
			table->items[index] = item;
			return ;
		}
		else
		{
			handle_collision(table, index, item);
			return ;
		}
	}
}
