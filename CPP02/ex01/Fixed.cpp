/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:58:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 12:52:08 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed &original) {
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed &Fixed::operator=(const Fixed &original) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &original) {
		return *this;
	}
	_fixedPointValue = original._fixedPointValue;
	return *this;
}

//converts int to the corresponding fixed-point value
Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intVal << _fractionalBitsValue;
}

//converts float to the corresponding fixed-point value
Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatVal * (1 << _fractionalBitsValue));
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

float Fixed::toFloat() const {
	return _fixedPointValue / (float)(1 << _fractionalBitsValue);
}

int	Fixed::toInt() const {
	return _fixedPointValue >> _fractionalBitsValue;
}

//The operator << is a special function that allows you to use the << operator
//to insert objects into an output stream 
//@std::ostream &os — stream to which the data will be written
//@const Fixed &fixed — object whose data we want to output
//After performing the insertion into the stream, the function returns the output stream os

std::ostream &operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
