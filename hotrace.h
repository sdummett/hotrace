/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:46:57 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/11 16:35:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#include "get_next_line.h"
#include <stdio.h> //TO DELETE

# define KEYWORD 0
# define VALUE 1

typedef struct s_data
{
    char             *keyword;
    char             *value;
    struct s_data    *next;
} t_data;

void	ft_lstadd_back(t_data **alst, t_data *new);
t_data  *ft_lstnew_korv(void *content, int bool);

#endif