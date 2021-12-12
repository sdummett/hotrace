/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:45:45 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 18:46:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_bucket	*init_bucket(t_bucket *new, t_ht_item *item)
{
	if (!new)
		return (NULL);
	new->item = item;
	new->next = NULL;
	return (new);
}

t_bucket	*allocate_bucket(void)
{
	t_bucket	*bucket;

	bucket = (t_bucket *)malloc(sizeof(t_bucket));
	return (bucket);
}
