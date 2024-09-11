/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:18:43 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 15:27:00 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

unsigned long	ft_atoul(const char *nbr)
{
	unsigned long	res;
	int				signal;

	res = 0;
	signal = 1;
	while (*nbr == 45 || *nbr == 43)
	{
		if (*nbr == 45)
			signal *= (-1);
		nbr++;
	}
	while (*nbr >= 48 && *nbr <= 57)
		res = res * 10 + (*nbr++ - 48);
	return (res * signal);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	res;

	i = 0;
	signal = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			signal *= (-1);
		nptr++;
	}
	while ((int)nptr[i] >= 48 && (int)nptr[i] <= 57)
		res = res * 10 + ((int)nptr[i++] - 48);
	return (res * signal);
}

bool	is_number(char *number)
{
	int	i;

	i = 0;
	while (number[i] == '-' || number[i] == '+')
		i++;
	if (number[i] == '\0')
		return (false);
	while (number[i] >= '0' && number[i] <= '9')
		i++;
	if (number[i] == '\0')
		return (true);
	return (false);
}
