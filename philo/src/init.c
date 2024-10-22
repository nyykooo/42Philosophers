/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:29:31 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/18 23:19:43 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

bool	ft_init_philo(t_philo *philo, t_table *table, int name)
{
	philo->t_die = table->t_die;
	philo->t_sleep = table->t_sleep;
	philo->t_eat = table->t_eat;
	philo->t_think = table->t_think;
	philo->t_start = table->t_start;
	philo->t_last_meal = table->t_start;
	philo->amount_eat = table->amount_eat;
	philo->name = name + 1;
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

void	ft_init_table(t_table *table, char **av)
{
	table->n_philo = ft_atoi(av[1]);
	table->t_die = ft_atoul(av[2]);
	table->t_eat = ft_atoul(av[3]);
	table->t_sleep = ft_atoul(av[4]);
	table->t_think = ft_get_time_think(table);
	table->amount_eat = -1;
	table->all_alive = true;
	table->all_eaten = false;
	table->start_dinner = false;
	if (av[5])
		table->amount_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&table->may_we, NULL) != 0
		|| pthread_mutex_init(&table->print_message, NULL) != 0)
	{
		ft_exit(table);
		return ;
	}
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philo)
		ft_exit(table);
	table->fork = (t_fork *)malloc(sizeof(t_fork) * table->n_philo);
	if (!table->fork)
		ft_exit(table);
	table->t_start = ft_gettimeofday_ms();
}

bool	ft_init_forks(t_fork *fork, int name)
{
	fork->id = name;
	fork->exist = false;
	if (pthread_mutex_init(&fork->fork, NULL) != 0)
		return (false);
	fork->exist = true;
	return (true);
}
