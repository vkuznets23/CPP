/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:00:08 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 16:36:24 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point {
private:
	Fixed	_x;
	Fixed	_y;

public:
	Point();				//default constructor
	Point(Fixed x, Fixed y);
	Point(const Point &origin);		//copy constructor
	~Point();				//destructor

	Point &operator=(const Point &origin); //Copyassignment operator

	//need these to reach _x and _y
	const Fixed &getX() const;
	const Fixed &getY() const;
};

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#endif
