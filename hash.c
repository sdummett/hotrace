/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:33:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 10:56:01 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

unsigned long	hash_function(char *str)
{
	unsigned long	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		i = i + str[j];
		j++;
	}
	return (i % CAPACITY);
}
