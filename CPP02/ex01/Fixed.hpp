/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:56:11 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 14:11:35 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
private:
	int			_fixedPointValue;
	static const int	_fractionalBitsValue = 8;
public:
	Fixed();
	Fixed(const Fixed &original);
	Fixed &operator = (const Fixed &original);
	Fixed(const int intVal);
	Fixed(const float floatVal);
	~Fixed();

	int	getRawBits() const;
	void	setRawBits(int const raw);

	float	toFloat() const;
	int	toInt() const;
};

std::ostream &operator << (std::ostream &os, const Fixed &fixed);

#endif
