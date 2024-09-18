/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:12:50 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/18 15:42:12 by ncampbel         ###   ########.fr       */
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

static void	ft_check_4deaths(t_table *table)
{
	unsigned int	i;
	unsigned int	n;

	while (table->all_alive == true && table->all_eaten == false)
	{
		i = 0;
		n = 0;
		while (i < table->n_philo)
		{
			pthread_mutex_lock(&table->philo[i].body);
			if (table->philo[i].amount_eat == 0)
				n++;
			if (n == table->n_philo)
				table->all_eaten = true;
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

static void	ft_init_table(t_table *table, char **av)
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
