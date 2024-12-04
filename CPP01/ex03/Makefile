# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 16:24:18 by vkuznets          #+#    #+#              #
#    Updated: 2024/12/04 16:24:20 by vkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
all: $(NAME)

CPP := c++
FLAGS := -Wall -Wextra -Werror -std=c++98

SOURCE := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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
