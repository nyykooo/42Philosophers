/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:22:04 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/18 21:29:44 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

static void	ft_start_together(t_table *table)
{
	while (1)
	{
		usleep(100);
		pthread_mutex_lock(&table->may_we);
		if (table->start_dinner == true)
		{
			pthread_mutex_unlock(&table->may_we);
			return ;
		}
		pthread_mutex_unlock(&table->may_we);
	}
}

static void	ft_synchornize(t_philo *philo)
{
	if (philo->table->n_philo % 2 == 1)
	{
		if ((unsigned int)philo->name == philo->table->n_philo)
			ft_better_you_sleep(philo->t_eat * 2, philo);
		else if (philo->name % 2 == 1)
			ft_better_you_sleep(philo->t_eat, philo);
	}
	else if (philo->name % 2 == 0)
		ft_better_you_sleep(philo->t_eat, philo);
}

static void	ft_habits(t_philo *philo)
{
	while (1)
	{
		ft_check_forks(philo);
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
		if (ft_check_stop_habits(philo) == true)
			return ;
	}
}

void	*ft_mind_hub(void *philosopher)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *)philosopher;
	table = philo->table;
	ft_start_together(table);
	ft_synchornize(philo);
	ft_habits(philo);
	return (NULL);
}

void	ft_create_philo(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (ft_init_philo(&table->philo[i], table, i) == false)
		{
			ft_exit(table);
			return ;
		}
		i++;
	}
	pthread_mutex_lock(&table->may_we);
	table->start_dinner = true;
	pthread_mutex_unlock(&table->may_we);
}
