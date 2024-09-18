# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncampbel <ncampbel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 22:06:25 by ncampbel          #+#    #+#              #
#    Updated: 2024/09/18 14:49:25 by ncampbel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

CC= cc

CFLAGS= -Wall -Wextra -Werror -g

LDFLAGS = -lpthread

VALFLAGS= -Wall -Wextra -Werror -g

SRC_DIR = table fork philo exit checks print time actions

SRC = $(addsuffix .c, $(addprefix src/, $(SRC_DIR)))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: fclean $(OBJ)
		$(CC) $(VALFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS);
		valgrind --tool=helgrind ./${NAME} 5 610 200 200

.PHONY: all clean fclean re

.SILENT:

