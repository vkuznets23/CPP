/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:13:54 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/23 10:29:26 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("dog"), _dogBrain(new Brain()) {
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _dogBrain(new Brain(*other._dogBrain)) {
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	Animal::operator = (other);
	delete _dogBrain;
	_dogBrain = new Brain(*other._dogBrain);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _dogBrain;
}

void	Dog::makeSound() const {std::cout << "Woof! Woof!" << std::endl; }

void Dog::setIdea(int index, const std::string &idea) {
	_dogBrain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return _dogBrain->getIdea(index);
}
