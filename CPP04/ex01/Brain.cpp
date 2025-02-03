/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:11:19 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 11:19:38 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Defaut brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "";
	}
}

Brain::Brain(const std::string ideas[100]) {
	std::cout << "Parameterized Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = ideas[i];
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Copy Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator = (const Brain &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {std::cout << "Brain destructor called" << std::endl; }

void	Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		_ideas[index] = idea;
	}
}

std::string	Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return _ideas[index];
	}
	return "";
}

