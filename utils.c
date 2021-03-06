/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:03:19 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/12 15:23:04 by ctchen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_bzero(void *b, size_t len)
{
	while (len)
	{
		*(unsigned char *)b = 0;
		b++;
		len--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	if (!(dest == src))
	{
		i = 0;
		while (n--)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src
					+ i);
			i++;
		}
	}
	return (dest);
}
