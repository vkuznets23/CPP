/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:58:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 13:15:49 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//fractionalBitsValue is laready set in .hpp
Fixed::Fixed() : _fixedPointValue(0) {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed &original) {
	std::cout << "Copy constructor called" << std::endl;
	// Directly copy the data members from original to the new object
	//_fixedPointValue = original._fixedPointValue; or this->_fixedPointValue = original._fixedPointValue
	*this = original;
}

Fixed &Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original) {
		return *this;
	}
	//_fixedPointValue = original._fixedPointValue;
	_fixedPointValue = original.getRawBits();
	return *this;
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function" << std::endl;
	_fixedPointValue = raw;
}
