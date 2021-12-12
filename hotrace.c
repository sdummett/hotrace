/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:43:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 18:06:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	get_datas(t_hashtable *table)
{
	char	*line;
	char	*key;
	int		type;
	int		ret;

	type = KEYWORD;
	ret = 1;
	key = NULL;
	while (ret > 0)
	{
		ret = get_next_line(0, &line);
		if (line[0] == '\0')
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
	if (type == VALUE)
		ht_insert(table, key, NULL);
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
	free_table(table);
	return (0);
}
