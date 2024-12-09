# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 15:50:19 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/09 13:17:24 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HarlComplains
CC = c++
CFLAGS = -Werror -Wall -Wextra

SRCS = Harl.cpp \
	main.cpp

HDRS = Harl.hpp

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
