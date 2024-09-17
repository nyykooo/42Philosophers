/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 21:22:55 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/17 16:38:19 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:27:46 by ncampbel          #+#    #+#             */
/*   Updated: 2024/08/11 19:03:07 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

bool	ft_check_stop_habits(t_philo *philo)
{
	pthread_mutex_lock(&philo->body);
	if (philo->amount_eat == -1 || philo->amount_eat > 0 || philo->stop == true)
	{
		pthread_mutex_unlock(&philo->body);
		return (true);
	}
	pthread_mutex_unlock(&philo->body);
	return (false);
}

void	ft_stop_dinner(t_table *table)
{
	unsigned int	i;

	i = -1;
	while (++i < table->n_philo)
	{
		pthread_mutex_lock(&table->philo[i].body);
		table->philo[i].stop = true;
		pthread_mutex_unlock(&table->philo[i].body);
	}
}

void	ft_eating(t_philo *philo)
{
	if (philo->l_fork && philo->r_fork)
	{
		pthread_mutex_lock(&philo->body);
		philo->t_last_meal = ft_gettimeofday_ms();
		ft_print_log(philo, "is eating", philo->t_last_meal);
		if (philo->amount_eat > 0)
			philo->amount_eat--;
		if (philo->amount_eat == 0)
			philo->stop = true;
		pthread_mutex_unlock(&philo->body);
		ft_better_you_sleep(philo->t_eat, philo);
	}
	if (philo->name % 2 == 1)
	{
		if (philo->r_fork != NULL)
			pthread_mutex_unlock(&philo->r_fork->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->r_fork->fork);
		pthread_mutex_unlock(&philo->l_fork->fork);
	}
}

void	ft_sleeping(t_philo *philo)
{
	ft_print_log(philo, "is sleeping", ft_gettimeofday_ms());
	ft_better_you_sleep(philo->t_sleep, philo);
	philo->is_awake = false;
}

void	ft_thinking(t_philo *philo)
{
	ft_print_log(philo, "is thinking", ft_gettimeofday_ms());
	ft_better_you_sleep(philo->t_think, philo);
	philo->is_awake = true;
}