# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 22:06:25 by ncampbel          #+#    #+#              #
#    Updated: 2024/09/11 17:15:39 by ncampbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

CC= cc

#DESCOBRIR PQ O -fsanitize=thread NAO FUNCIONA

FLAGS= -Wall -Wextra -Werror -g -fsanitize=thread

VALFLAGS= -Wall -Wextra -Werror -g

SRC_DIR = table fork philo exit checks print

SRC = $(addsuffix .c, $(addprefix src/, $(SRC_DIR)))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: fclean $(OBJ)
		$(CC) $(VALFLAGS) $(OBJ) -o $(NAME);
		valgrind --tool=helgrind ./${NAME}

.PHONY: all clean fclean re

.SILENT:

