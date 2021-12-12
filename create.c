/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:36:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 15:37:55 by ctchen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_ht_item	*create_item(char *key, char *value)
{
	t_ht_item	*item;

	item = (t_ht_item *)malloc(sizeof(t_ht_item));
	item->key = key;
	item->value = value;
	return (item);
}

t_bucket	**create_buckets(t_hashtable *table)
{
	t_bucket	**buckets;
	int			i;

	buckets = (t_bucket **)ft_calloc(table->size, sizeof(t_bucket *));
	i = 0;
	while (i < table->size)
	{
		buckets[i] = NULL;
		i++;
	}
	return (buckets);
}

t_hashtable	*create_table(int size)
{
	int				i;
	t_hashtable		*table;

	table = (t_hashtable *)malloc(sizeof(t_hashtable));
	table->size = size;
	table->count = 0;
	table->items = (t_ht_item **) ft_calloc(table->size, sizeof(t_ht_item *));
	i = 0;
	while (i < table->size)
	{
		table->items[i] = NULL;
		i++;
	}
	table->buckets = create_buckets(table);
	return (table);
}
