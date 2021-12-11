/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:18:00 by ctchen            #+#    #+#             */
/*   Updated: 2021/12/11 14:56:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_lstadd_back(t_data **alst, t_data *new)
{
	t_data	*ptr;

	ptr = *alst;
	if (!*alst)
		*alst = new;
	else
	{
		while (ptr && ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
