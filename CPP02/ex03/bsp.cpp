/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:18:37 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 14:20:22 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//create a triangle
Fixed	sign(const Point &p1, const Point &p2, const Point &p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}


//if the result of cross producct is positive then vector is to the left
bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
	Fixed crossAB = sign(a, b, point);  // Cross product for triangle edge AB
	Fixed crossBC = sign(b, c, point);  // Cross product for triangle edge BC
	Fixed crossCA = sign(c, a, point);  // Cross product for triangle edge CA

	// Check if the point is on the same side of all triangle edges
	bool same_signs = (crossAB > 0 && crossBC > 0 && crossCA > 0)
			|| (crossAB < 0 && crossBC < 0 && crossCA < 0);

	// If the point is on the same side (either left or right) of all edges, it's inside the triangle
	bool isOnEdge = (crossAB == 0 || crossBC == 0 || crossCA == 0);

	return same_signs && !isOnEdge;
}
