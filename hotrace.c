/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:43:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 12:18:17 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	init_alpha_table(t_alpha_table *alpha_table)
{
	unsigned int	i;

	i = 0;
	while (i < ALPHA_TABLE_SIZE)
	{
		alpha_table[i].table = NULL;
		i++;
	}
}
 
// void print_table(t_hashtable* table)
// {
//     printf("\nHash Table\n-------------------\n");
//     for (int i=0; i<table->size; i++) {
//         if (table->items[i]) {
//             printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
//         }
//     }
//     printf("-------------------\n\n");
// }

int	get_datas(t_alpha_table *alpha_table)
{
	char	*line;
	char	*key;
	int		type;
	int		ret;

	type = KEYWORD;
	printf("Entering get_datas...\n");
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (ft_strlen(line) == 0)
		{
			free(line);
			break ;
		}
		if (type == KEYWORD)
		{
			if (alpha_table[(unsigned int)line[0]].table == NULL)
				alpha_table[(unsigned int)line[0]].table =
					create_table(CAPACITY);
			key = line;
			type = VALUE;
		}
		else if (type == VALUE)
		{
			ht_insert(alpha_table[(unsigned int)key[0]].table, key, line);
			type = KEYWORD;
		}
	}
	return (ret);
}

int	main(void)
{
	int				ret;
	t_alpha_table	alpha_table[ALPHA_TABLE_SIZE];

	init_alpha_table(alpha_table);
	ret = get_datas(alpha_table);
	if (ret > 0)
		search_datas(alpha_table);
	return (0);
}
