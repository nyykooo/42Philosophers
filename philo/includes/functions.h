/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:14:22 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 15:54:50 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

// PARSING CHECK FUNCTIONS
unsigned long	ft_atoul(const char *nbr);
int				ft_atoi(const char *nptr);
bool			is_number(char *number);

// FORK FUNCTIONS
void			ft_create_forks(t_table *table);

// PHILO FUNCTIONS
void			ft_create_philo(t_table *table);

// EXIT FUNCTIONS
void			ft_exit(t_table *table);

// PRINT FUNCTIONS
void	ft_print_log(int name, t_table *table, \
char *message, unsigned long time);

#endif
