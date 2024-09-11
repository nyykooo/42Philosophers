/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:03:25 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 15:55:50 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

static void	ft_clear_philos(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n_philo && &table->philo[i])
	{
		pthread_mutex_destroy(&table->philo[i].body);
		ft_print_log(table->philo[i].name, table, "has died", 100);
		i++;
	}
}

static void	ft_clear_forks(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n_philo && table->fork[i].exist)
	{
		pthread_mutex_destroy(&table->fork[i].fork);
		ft_print_log(table->fork[i].id, table, "fork has been destroyed", 101);
		i++;
	}
}

static void	ft_clear_table(t_table *table)
{
	if (table)
	{
		if (!table->philo)
			return ;
		if (table->philo)
			free(table->philo);
		if (!table->fork)
			return ;
		if (table->fork)
			free(table->fork);
		pthread_mutex_destroy(&table->may_we);
		pthread_mutex_destroy(&table->print_message);
	}
}

void	ft_exit(t_table *table)
{
	ft_clear_philos(table);
	ft_clear_forks(table);
	ft_clear_table(table);
}
