/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:43:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/11 16:52:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	printlst(t_data *lst)
{
	while (lst != NULL)
	{
		printf("KEYWORD => %s\n", lst->keyword);
		printf("VALUE   => %s\n\n", lst->value);
		lst = lst->next;
	}
}

void lstaddvalue(t_data *data, char *content)
{
	while (data->next)
	{
		data = data->next;
	}
	data->value = content;
}

int get_datas(t_data **data)
{
	(void)data;

    char    *line;
	int		type;

	type = KEYWORD;
    while (get_next_line(0, &line) > 0)
    {
		printf("line => %s\n", line);
		if (ft_strlen(line) == 0)
	   	{
			free(line);
			break ;
		}
		if (type == KEYWORD)
		{
			ft_lstadd_back(data, ft_lstnew_korv(line, type));
			type = VALUE;
		}
		else if (type == VALUE)
		{
			lstaddvalue(*data, line);
			type = KEYWORD;
		}

    }
	printlst(*data);
	return (0);
}

int main(int ac, char **av)
{
    t_data *data;
    (void)ac;
    (void)av;

    data = NULL;
    get_datas(&data);
	printf("Now searching keywords\n");
	//search_datas(&data);
    return (0);
}
