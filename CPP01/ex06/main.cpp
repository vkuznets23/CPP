/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:07 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 16:08:40 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl		harl;
	int		caseNum;
	std::string	level;

	if (ac < 2) {
		std::cout << "./harlFilter levelName" << std::endl;
		return (1);
	}

	level = av[1];
	if (level == "DEBUG")
		caseNum = 1;
	else if (level == "INFO")
		caseNum = 2;
	else if (level == "WARNING")
		caseNum = 3;
	else if (level == "ERROR")
		caseNum = 4;

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
