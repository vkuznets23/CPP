/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:18:37 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 16:24:18 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	cross(const Point &a, const Point &b, const Point &c) {
	return (b.getX() - a.getX()) * (c.getX() - a.getX()) -
		(b.getY() - a.getY()) * (c.getY() - a.getY());
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    Fixed cross1 = cross(a, b, point);  // Cross product for triangle edge AB
    Fixed cross2 = cross(b, c, point);  // Cross product for triangle edge BC
    Fixed cross3 = cross(c, a, point);  // Cross product for triangle edge CA

    // Check if all cross products have the same sign
    bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);

    return !(has_neg && has_pos);  // True if all are positive or negative
}
