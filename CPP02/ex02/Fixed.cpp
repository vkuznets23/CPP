/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:58:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 13:09:30 by vkuznets         ###   ########.fr       */
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

Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intVal << _fractionalBitsValue;
}

Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatVal * (1 << _fractionalBitsValue));
}

Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function" << std::endl;
	_fixedPointValue = raw;
}

float	Fixed::toFloat() const {
	return _fixedPointValue / (float)(1 << _fractionalBitsValue);
}

int	Fixed::toInt() const {
	return _fixedPointValue >> _fractionalBitsValue;
}

//comparison operators
bool	Fixed::operator!=(const Fixed &original) const {return _fixedPointValue != original._fixedPointValue; }
bool	Fixed::operator==(const Fixed &original) const {return _fixedPointValue == original._fixedPointValue; }
bool	Fixed::operator<=(const Fixed &original) const {return _fixedPointValue <= original._fixedPointValue; }
bool	Fixed::operator>=(const Fixed &original) const {return _fixedPointValue >= original._fixedPointValue; }
bool	Fixed::operator>(const Fixed &original) const {return _fixedPointValue > original._fixedPointValue; }
bool	Fixed::operator<(const Fixed &original) const {return _fixedPointValue < original._fixedPointValue; }

//arithmetic operators
Fixed	Fixed::operator+(const Fixed &original) const {
	Fixed	temp;
	temp.setRawBits(_fixedPointValue + original._fixedPointValue);
	return temp;
}

Fixed	Fixed::operator-(const Fixed &original) const {
	Fixed	temp;
	temp.setRawBits(_fixedPointValue - original._fixedPointValue);
	return temp;
}

Fixed	Fixed::operator*(const Fixed &original) const {return (Fixed(this->toFloat() * original.toFloat())); }
Fixed	Fixed::operator/(const Fixed &original) const {return (Fixed(this->toFloat() / original.toFloat())); }

//++a, a++, --a, a--
Fixed	&Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed	&Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp(*this);		//create a temp copy of this
	this->_fixedPointValue++;
	return temp;
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);		//create a temp copy of this
	this->_fixedPointValue--;
	return temp;
}

//min functions
Fixed	&Fixed::min(Fixed &num1, Fixed &num2) {
	return num1 < num2 ? num1 : num2;
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
	return num1 < num2 ? num1 : num2;
}

//max functions
Fixed	&Fixed::max(Fixed &num1, Fixed &num2) {
	return num1 > num2 ? num1 : num2;
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
	return num1 > num2 ? num1 : num2;
}

std::ostream &operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
