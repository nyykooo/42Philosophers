/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:45 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/16 19:51:08 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

unsigned long	ft_get_time_think(t_table *table)
{
	unsigned long	t_think;

	if (table->n_philo % 2 == 1)
		t_think = table->t_eat * 2 - table->t_sleep;
	else if (table->t_eat > table->t_sleep)
		t_think = table->t_eat - table->t_sleep;
	else
		t_think = 0;
	return (t_think);
}

unsigned long	ft_gettimeofday_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000);
}

void	ft_better_you_sleep(unsigned long delay_ms, t_philo *philo)
{
	unsigned long	deadline;

	deadline = ft_gettimeofday_ms() + delay_ms;
	while (ft_gettimeofday_ms() <= deadline)
	{
		pthread_mutex_lock(&philo->body);
		if (philo->stop == true)
		{
			pthread_mutex_unlock(&philo->body);
			return ;
		}
		pthread_mutex_unlock(&philo->body);
		usleep(500);
	}
}
