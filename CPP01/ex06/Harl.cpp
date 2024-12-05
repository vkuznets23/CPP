/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:55:39 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/05 16:03:59 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::_debug(void) {
	std::cout << "DEBUG: I love having extra bacon for my burger" << std::endl;
}

void	Harl::_info(void) {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money." << std::endl;
}

void	Harl::_warning(void) {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free." << std::endl;
}

void	Harl::_error(void) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	void (Harl::*functionPTRs[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string arrayLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++) {
		if (arrayLevels[i] == level) {
			(this->*functionPTRs[i])();
			return ;
		}
	}
}
