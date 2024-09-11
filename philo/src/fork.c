/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:22:02 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 15:26:55 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

// static bool	init_philo(t_philo *philo, t_table *table, int name)
// {
// 	philo->t_die = table->t_die;
// 	philo->t_sleep = table->t_sleep;
// 	philo->t_eat = table->t_eat;
// 	philo->t_think = get_t_think(table);
// 	philo->th_amount_eat = table->th_amount_eat;
// 	philo->th_name = name + 1;
// 	philo->table = table;
// 	philo->is_awake = true;
// 	philo->stop = false;
// 	philo->t_last_meal = table->th_start;
// 	philo->l_fork = &table->fork[name];
// 	if ((unsigned int)philo->th_name ==
//		table->th_n_philo && table->th_n_philo != 1)
// 		philo->r_fork = &table->fork[0];
// 	else if (table->n_philo != 1)
// 		philo->r_fork = &table->fork[name + 1];
// 	else
// 		philo->r_fork = NULL;
// 	if (pthread_mutex_init(&philo->body, NULL) != 0)
// 		return (false);
// 	if (pthread_create(&philo->mind, NULL, mind_hub,
// 			philo) != 0)
// 		return (false);
// 	return (true);
// }

// void	create_philo(t_table *table)
// {
// 	unsigned int	i;

// 	i = 0;
// 	pthread_mutex_lock(&table->may_we);
// 	while (i < table->n_philo)
// 	{
// 		if (init_philo(&table->philo[i], table, i) == false)
// 		{
// 			ft_exit(table);
// 			pthread_mutex_unlock(&table->may_we);
// 			return ;
// 		}
// 		i++;
// 	}
// 	pthread_mutex_unlock(&table->may_we);
// }

static bool	ft_init_forks(t_fork *fork, int name)
{
	fork->id = name;
	fork->exist = false;
	printf("Fork %d\n", fork->id);
	if (pthread_mutex_init(&fork->fork, NULL) != 0)
		return (false);
	fork->exist = true;
	return (true);
}

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
