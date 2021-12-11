/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctchen <ctchen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:34:45 by ctchen            #+#    #+#             */
/*   Updated: 2021/12/11 17:52:16 by ctchen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_binary_s(long long **tab, long long val_s)
{
	long long	i;

	i = 0;
	while (tab[i])
		i++;
	i = i / 2;// a modifier
	while (val_s != tab[i][0])
	{
		if (val_s < tab[i][0])
			i--;
		else if (val_s > tab[i][0])
			i++;
	}
	return (i);
}
