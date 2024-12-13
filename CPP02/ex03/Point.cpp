/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:04:26 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 13:57:59 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(), _y() {}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

Point::Point (const Point &origin) {
	*this = origin;
}

Point::~Point() {}

Point	&Point::operator = (const Point &origin) {
	if (this != &origin) {
		this->_x = origin._x;
		this->_y = origin._y;
	}
	return *this;
}

const Fixed	&Point::getX() const {
	return _x;
}

const Fixed	&Point::getY() const {
	return _y;
}
