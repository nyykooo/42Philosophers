/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:22:04 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/17 16:40:32 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

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

	philo = (t_philo *)philosopher;
	ft_synchornize(philo);
	ft_habits(philo);
	return (NULL);
}

static bool	ft_init_philo(t_philo *philo, t_table *table, int name)
{
	philo->t_die = table->t_die;
	philo->t_sleep = table->t_sleep;
	philo->t_eat = table->t_eat;
	philo->t_think = table->t_think;
	philo->t_start = table->t_start;
	philo->t_last_meal = table->t_start;
	philo->amount_eat = table->amount_eat;
	philo->name = name + 1;
	philo->is_awake = true;
	philo->stop = false;
	philo->l_fork = &table->fork[name];
	if ((unsigned int)philo->name == table->n_philo && table->n_philo != 1)
		philo->r_fork = &table->fork[0];
	else if (table->n_philo != 1)
		philo->r_fork = &table->fork[name + 1];
	else
		philo->r_fork = NULL;
	philo->table = table;
	if (pthread_mutex_init(&philo->body, NULL) != 0)
		return (false);
	if (pthread_create(&philo->mind, NULL, ft_mind_hub,
			philo) != 0)
		return (false);
	return (true);
}

void	ft_create_philo(t_table *table)
{
	int	i;

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
}
