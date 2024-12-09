# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 12:08:16 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/09 16:40:00 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = insideTriangle
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = Fixed.cpp \
	Point.cpp \
	bsp.cpp \
	main.cpp

HDRS = Fixed.hpp \
	Point.hpp

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
