/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:56:11 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 13:11:09 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
private:
	int			_fixedPointValue;
	static const int	_fractionalBitsValue = 8;
public:
	//defult constructor
	Fixed();

	//copy constructor (creates new object as a copy)
	Fixed(const Fixed &original);

	//copy assignment operator (copy the content of one obj to existing another one
	Fixed &operator = (const Fixed &original);

	//destructor
	~Fixed();

	//return raw value of _fixedPointValue
	int	getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
