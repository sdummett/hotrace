/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:05:50 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 11:51:28 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	free_item(t_ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

t_ht_item	*bucket_remove(t_bucket *list)
{
    // Removes the head from the linked list
    // and returns the item of the popped element
	t_ht_item	*item;
	t_bucket	*node;
	t_bucket	*temp;

	if (!list)
		return (NULL);
	if (!list->next)
		return (NULL);
	node = list->next;
	temp = list;
	temp->next = (NULL);
	list = node;
	item = (NULL);
	ft_memcpy(temp->item, item, sizeof(t_ht_item));
	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);
	return (item);
}

void	free_buckets(t_bucket *list)
{
	t_bucket	*temp;

	temp = list;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->item->key);
		free(temp->item->value);
		free(temp->item);
		free(temp);
	}
}

void	free_buckets_arrays(t_hashtable *table)
{
    // Free all the overflow bucket lists
	int			i;
	t_bucket	**buckets;

	buckets = table->buckets;
	i = 0;
	while (i < table->size)
	{
		free_buckets(buckets[i]);
		i++;
	}
	free(buckets);
}

void	free_table(t_hashtable *table)
{
	int	i;

	i = 0;
	while (i < table->size)
	{
		if (table->items[i] != NULL)
			free_item(table->items[i]);
		i++;
	}
	free_buckets_arrays(table);
	free(table->items);
	free(table);
}
