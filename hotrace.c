/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:43:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 15:38:40 by ctchen           ###   ########.fr       */
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

int	get_datas(t_hashtable *table)
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
			key = line;
			type = VALUE;
		}
		else if (type == VALUE)
		{
			ht_insert(table, key, line);
			type = KEYWORD;
		}
	}
	return (ret);
}

int	main(void)
{
	int				ret;
	t_hashtable		*table;

	table = create_table(CAPACITY);
	ret = get_datas(table);
	if (ret > 0)
		search_datas(table);
	return (0);
}
