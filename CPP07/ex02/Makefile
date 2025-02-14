# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 10:04:09 by vkuznets          #+#    #+#              #
#    Updated: 2025/02/14 10:04:30 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = array
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11


SRCS = main.cpp 

HDRS = Array.hpp \
	Array.tpp

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