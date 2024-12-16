/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:43:02 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/16 16:19:12 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() _type("default materia") {std::cout << "Default constructor called" << std::endl; }

AMateria::AMateria(const std::string &type) : _type(type) {std::cout << "Parameterized constructor called" << std::endl; }

AMateria::AMateria(const AMateria &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		_type = other._type;	
	}
	return *this;
}

AMateria::~AMateria() {std::cout << "Desctructor called" << std::endl; }

std::string const AMateria &getType() const {
	return _type;
}
