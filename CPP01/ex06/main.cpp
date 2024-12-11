/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:07 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/11 11:30:35 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	getLevelCaseNumber(const std::string& level) {
	if (level == "DEBUG") {
		return 1;
	} else if (level == "INFO") {
		return 2;
	} else if (level == "WARNING") {
		return 3;
	} else if (level == "ERROR") {
		return 4;
	}
	return 0; // Invalid level, returning default case number 0
}

int	main(int ac, char **av) {
	Harl		harl;
	int		caseNum;
	std::string	level;

	if (ac != 2) {
		std::cout << "Usage: ./harlFilter [level]" << std::endl;
		return 1;
	}

	level = av[1];
	caseNum = getLevelCaseNumber(level);

	switch (caseNum) {
		case 1:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break ;
		case 2:
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break ;
		case 3:
			harl.complain("WARNING");
			harl.complain("ERROR");
			break ;
		case 4:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "Invalid option\n";
	}
}
