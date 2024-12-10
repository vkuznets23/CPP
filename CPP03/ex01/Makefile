# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 14:39:14 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/10 16:32:01 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScravTrap
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = ClapTrap.cpp \
	ScavTrap.cpp \
	main.cpp

HDRS = ClapTrap.hpp \
	ScavTrap.hpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
