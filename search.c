/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:20:25 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 17:49:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*hashtable_search(t_hashtable *table, char *key)
{
	int			index;
	t_ht_item	*item;
	t_bucket	*head;

	index = hash_function(key);
	item = table->items[index];
	head = table->buckets[index];
	while (item != NULL)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key)) == 0)
			return (item->value);
		if (head == NULL)
			return (NULL);
		item = head->item;
		head = head->next;
	}
	return (NULL);
}

void	print_search(t_hashtable *table, char *key)
{
	char	*val;

	if (table == NULL)
	{
		ft_putstr(key);
		ft_putstr(": Not found.\n");
		return ;
	}
	val = hashtable_search(table, key);
	if (val == NULL)
	{
		ft_putstr(key);
		ft_putstr(": Not found.\n");
		return ;
	}
	else
	{
		ft_putstr(val);
		ft_putstr("\n");
	}
}

void	search_datas(t_hashtable *table)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '\0')
			free(line);
		else
		{
			print_search(table, line);
			free(line);
		}
	}
	if (line && line[0] == '\0')
		free(line);
	else if (line)
	{
		print_search(table, line);
		free(line);
	}
}
