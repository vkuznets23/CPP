# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 10:04:09 by vkuznets          #+#    #+#              #
#    Updated: 2025/02/19 15:44:55 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easyfind
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11


SRCS = main.cpp 

HDRS = easyfind.hpp \
	easyfind.tpp

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