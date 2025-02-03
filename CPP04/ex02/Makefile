# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 11:11:36 by vkuznets          #+#    #+#              #
#    Updated: 2025/01/23 10:35:04 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  Abstract
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = Animal.cpp \
	Dog.cpp \
	Cat.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \
	Brain.cpp \
	main.cpp

HDRS = Animal.hpp \
	Dog.hpp \
	WrongAnimal.hpp \
	WrongCat.hpp \
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
