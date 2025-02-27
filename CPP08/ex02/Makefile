# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 17:32:31 by viktoria          #+#    #+#              #
#    Updated: 2025/02/27 17:33:29 by viktoria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Mutant
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++17


SRCS = main.cpp \

HDRS = MutantStack.hpp \
	MutantStack.tpp

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