# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 10:04:09 by vkuznets          #+#    #+#              #
#    Updated: 2025/02/26 14:57:15 by viktoria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17


SRCS = main.cpp \
	Span.cpp

HDRS = Span.hpp \

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