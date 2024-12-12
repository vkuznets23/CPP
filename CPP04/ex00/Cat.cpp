/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:17:31 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/12 11:25:34 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat") {std::cout << "Default Cat constructor" << std::endl; }

Cat::Cat(const Cat &origin) : Animal(origin) {std::cout << "Copy Cat constructor called" << std::endl; }

Cat &Cat::operator=(const Cat &origin) {
	if (this == &origin) {
		return *this;
	}
	(Animal::operator=(origin));
	return *this;
}

Cat::~Cat() {std::cout << "Cat destructor" << std::endl; }

void	Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}

