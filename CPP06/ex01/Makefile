# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:11:36 by vkuznets          #+#    #+#              #
#    Updated: 2025/02/07 12:55:20 by viktoria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serializer
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11


SRCS = Serializer.cpp \
	main.cpp

HDRS = Serializer.hpp \
	Data.hpp

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

tester:
	g++ -Wall -Wextra -Werror -std=c++11 tester.cpp -o tester

.PHONY: all clean fclean re