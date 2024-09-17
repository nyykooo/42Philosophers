/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:14:22 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/17 16:33:48 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// PARSING CHECK FUNCTIONS
bool			is_number(char *number);
unsigned long	ft_atoul(const char *nbr);
int				ft_atoi(const char *nptr);

// ACTIONS FUNCTIONS
void			ft_eating(t_philo *philo);
void			ft_thinking(t_philo *philo);
void			ft_sleeping(t_philo *philo);
void			ft_stop_dinner(t_table *table);
bool			ft_check_stop_habits(t_philo *philo);

// FORK FUNCTIONS
void			ft_create_forks(t_table *table);
void			ft_check_forks(t_philo *philo);

// PHILO FUNCTIONS
void			ft_create_philo(t_table *table);

// EXIT FUNCTIONS
void			ft_exit(t_table *table);

// PRINT FUNCTIONS
void			ft_death_eaten(t_table *table, int name);
void			ft_print_log(t_philo *philo, char *message, unsigned long time);

// TIME FUNCTIONS
unsigned long	ft_gettimeofday_ms(void);
unsigned long	ft_get_time_think(t_table *table);
void			ft_better_you_sleep(unsigned long delay_ms, t_philo *philo);

#endif
