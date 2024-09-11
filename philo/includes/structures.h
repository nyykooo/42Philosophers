/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:14:17 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 15:33:26 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "headers.h"

typedef struct s_fork
{
	int				id;
	bool			exist;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	// unsigned long	t_think;
	// unsigned long	t_last_meal;
	int				amount_eat;
	int				name;
	bool			is_awake;
	bool			stop;
	t_fork			*l_fork;
	t_fork			*r_fork;
	pthread_t		mind;
	pthread_mutex_t	body;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	unsigned long	t_die;
	unsigned long	t_eat;
	unsigned long	t_sleep;
	int				amount_eat;
	unsigned int	n_philo;
	bool			all_alive;
	bool			all_eaten;
	pthread_mutex_t	may_we;
	pthread_mutex_t	print_message;
	t_philo			*philo;
	t_fork			*fork;
}	t_table;

#endif