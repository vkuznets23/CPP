/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:24:09 by vkuznets          #+#    #+#             */
/*   Updated: 2025/01/22 10:53:26 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat") {std::cout << "Default Cat constructor called" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other) {std::cout << "Copy Cat constructor called" << std::endl; }

Cat &Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	Animal::operator = (other);
	return *this;
}

Cat::~Cat() {std::cout << "Cat destructor called" << std::endl; }

void	Cat::makeSound() const {std::cout << "Meow! Meow!" << std::endl; }
