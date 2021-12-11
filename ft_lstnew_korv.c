/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_korv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:00:50 by ctchen            #+#    #+#             */
/*   Updated: 2021/12/11 15:27:02 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_data	*ft_lstnew_korv(void *content, int bool)
{
	t_data	*strc;

	strc = (t_data *)malloc(sizeof(*strc));
	if (!strc)
		return (0);
	if (bool == KEYWORD)
		strc->keyword = content;
	else if (bool == VALUE)
		strc->value = content;
	strc->next = 0;
	return (strc);
}
