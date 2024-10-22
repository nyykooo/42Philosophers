/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:22:02 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/18 21:30:49 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	ft_create_forks(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (!ft_init_forks(&table->fork[i], i))
		{
			ft_exit(table);
			return ;
		}
		i++;
	}
}

void	ft_check_forks(t_philo *philo)
{
	if (philo->name % 2 == 1 && philo->l_fork != NULL)
		pthread_mutex_lock(&philo->l_fork->fork);
	else if (philo->r_fork != NULL)
		pthread_mutex_lock(&philo->r_fork->fork);
	ft_print_log(philo, "has taken a fork", ft_gettimeofday_ms());
	if (philo->table->n_philo != 1)
	{
		if (philo->name % 2 == 1 && philo->r_fork != NULL)
			pthread_mutex_lock(&philo->r_fork->fork);
		else if (philo->l_fork != NULL)
			pthread_mutex_lock(&philo->l_fork->fork);
		ft_print_log(philo, "has taken a fork", ft_gettimeofday_ms());
	}
}
