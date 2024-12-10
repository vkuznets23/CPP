# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 16:24:18 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/10 12:59:48 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp \
	main.cpp

HDRS = HumanA.hpp \
	HumanB.hpp \
	Weapon.hpp

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
