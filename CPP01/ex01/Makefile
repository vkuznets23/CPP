# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:51:59 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/04 15:52:02 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = make_horde
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

SOURCE := main.cpp Zombie.cpp zombieHorde.cpp
OBJ := $(SOURCE:.cpp=.o)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME) 

%.o : %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
