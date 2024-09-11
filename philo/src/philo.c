/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:22:04 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 16:07:51 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	*ft_mind_hub(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	pthread_mutex_lock(&philo->table->may_we);
	ft_print_log(philo->name, philo->table, "is thinking", 0);
	pthread_mutex_unlock(&philo->table->may_we);
	return (NULL);
}

static bool	ft_init_philo(t_philo *philo, t_table *table, int name)
{
	philo->t_die = table->t_die;
	philo->t_sleep = table->t_sleep;
	philo->t_eat = table->t_eat;
	philo->amount_eat = table->amount_eat;
	philo->name = name + 1;
	philo->is_awake = true;
	philo->stop = false;
	philo->l_fork = &table->fork[name];
	if (table->n_philo == 1)
		philo->r_fork = NULL;
	else if (name == table->n_philo - 1)
		philo->r_fork = &table->fork[0];
	else
		philo->r_fork = &table->fork[(name + 1)];
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
	pthread_mutex_lock(&table->may_we);
	while (i < table->n_philo)
	{
		if (ft_init_philo(&table->philo[i], table, i) == false)
		{
			ft_exit(table);
			return ;
		}
		i++;
	}
	ft_print_log(0, table, "All philosophers are ready", 99);
	pthread_mutex_unlock(&table->may_we);
}
