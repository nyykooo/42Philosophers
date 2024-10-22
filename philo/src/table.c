/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:12:50 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/18 23:25:18 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

static void	ft_wait_threads(t_table *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->n_philo)
		pthread_join(table->philo[i++].mind, NULL);
}

static void	ft_amount_to_eat(t_table *table, unsigned int i, unsigned int *n)
{
	if (table->philo[i].amount_eat == 0)
		*n += 1;
	if (*n == table->n_philo)
		table->all_eaten = true;
}

static void	ft_check_4deaths(t_table *table)
{
	unsigned int	i;
	unsigned int	n;

	usleep(6000);
	while (table->all_alive == true && table->all_eaten == false)
	{
		i = 0;
		n = 0;
		while (i < table->n_philo)
		{
			usleep(1000);
			pthread_mutex_lock(&table->philo[i].body);
			ft_amount_to_eat(table, i, &n);
			if ((table->philo[i].amount_eat == -1
					|| table->philo[i].amount_eat > 0) && (ft_gettimeofday_ms()
					- table->philo[i].t_last_meal > table->t_die))
			{
				ft_death_eaten(table, i);
				return ;
			}
			pthread_mutex_unlock(&table->philo[i].body);
			i++;
		}
	}
}

static bool	ft_parse_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (false);
	if (!is_number(av[1]) || !is_number(av[2]) || !is_number(av[3])
		|| !is_number(av[4]))
		return (false);
	else if (ac == 6 && !is_number(av[5]))
		return (false);
	if (ft_atoi(av[1]) <= 0 || ft_atoul(av[2]) <= 0 || ft_atoul(av[3]) <= 0
		|| ft_atoul(av[4]) <= 0)
		return (false);
	else if (ft_atoul(av[2]) > LONG_MAX || ft_atoul(av[3]) > LONG_MAX
		|| ft_atoul(av[4]) > LONG_MAX)
		return (false);
	else if (ac == 6 && (ft_atoi(av[5]) < 0 || ft_atoi(av[5]) == 0))
		return (false);
	if (ft_atoi(av[1]) > 200)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	static t_table	table;

	if (ft_parse_input(ac, av) == true)
	{
		ft_init_table(&table, av);
		if (table.fork)
			ft_create_forks(&table);
		if (table.philo && table.fork)
			ft_create_philo(&table);
		if (table.philo)
			ft_check_4deaths(&table);
		if (table.philo)
			ft_wait_threads(&table);
	}
	ft_exit(&table);
	return (0);
}
