# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 10:50:53 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/10 10:57:09 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = makeHorde
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = Zombie.cpp \
	zombieHorde.cpp \
	main.cpp

HDRS = Zombie.hpp

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
