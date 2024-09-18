/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:47:21 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/18 14:50:02 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	ft_print_log(t_philo *philo, char *message, unsigned long time)
{
	pthread_mutex_lock(&philo->table->print_message);
	if (philo->table->all_alive == true)
	{
		printf("%lu %d %s\n", time - philo->t_start, philo->name, message);
	}
	pthread_mutex_unlock(&philo->table->print_message);
}

void	ft_death_eaten(t_table *table, int name)
{
	pthread_mutex_lock(&table->print_message);
	printf("%ld %d died\n", ft_gettimeofday_ms() - table->t_start,
		table->philo[name].name);
	table->all_alive = false;
	pthread_mutex_unlock(&table->print_message);
	pthread_mutex_unlock(&table->philo[name].body);
	ft_stop_dinner(table);
}
