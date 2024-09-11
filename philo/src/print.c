/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:47:21 by ncampbel          #+#    #+#             */
/*   Updated: 2024/09/11 15:56:22 by ncampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/headers.h"

void	ft_print_log(int name, t_table *table, \
char *message, unsigned long time)
{
	pthread_mutex_lock(&table->print_message);
	printf("%lu %d %s\n", time, name, message);
	pthread_mutex_unlock(&table->print_message);
}
