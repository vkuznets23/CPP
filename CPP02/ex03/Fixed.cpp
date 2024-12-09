/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:58:47 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 16:38:46 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const Fixed &original) {
	*this = original;
}

Fixed &Fixed::operator=(const Fixed &original) {
	if (this == &original) {
		return *this;
	}
	_fixedPointValue = original._fixedPointValue;
	return *this;
}

Fixed::Fixed(const int intVal) {
	_fixedPointValue = intVal << _fractionalBitsValue;
}

Fixed::Fixed(const float floatVal) {
	_fixedPointValue = roundf(floatVal * (1 << _fractionalBitsValue));
}

Fixed::~Fixed() {}

int	Fixed::getRawBits() const {
	return _fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
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
	temp.setRawBits(_fixedPointValue + original._fixedPointValue);
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
