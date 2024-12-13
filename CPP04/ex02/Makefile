# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:11:36 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/12 15:48:37 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	Brain.cpp \
	main.cpp

HDRS = Animal.hpp \
	Dog.hpp \
	Brain.hpp \
	Cat.hpp

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
