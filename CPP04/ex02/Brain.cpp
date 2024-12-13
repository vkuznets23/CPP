/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:21:08 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 15:52:49 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default Brain constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "";
	}
}

Brain::Brain(std::string ideas[100]){
	std::cout << "Parameterized Brain constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = ideas[i];
	}
}

Brain::Brain(const Brain &origin) {
	std::cout << "Copy Brain constructor" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = origin._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &origin) {
	if (this == &origin) {
		return *this;
	}
	for (int i = 0; i < 100; i++) {
		_ideas[i] = origin._ideas[i];
	}
	return *this;
}

Brain::~Brain() {std::cout << "Destructor Brain called" << std::endl; }
