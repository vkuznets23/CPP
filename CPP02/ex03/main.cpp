/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:09:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/13 14:31:59 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void testPoint(float x1, float y1,
			   float x2, float y2,
			   float x3, float y3,
			   float px, float py)
{
	Point a(x1, y1);
	Point b(x2, y2);
	Point c(x3, y3);
	Point p(px, py);

	std::cout << (bsp(a, b, c, p) ? "Yes" : "No") << std::endl;
}

int main() {

	testPoint(-1, 0, 0, 1, 1, 0, 0, 0.5);
	testPoint(1, 1, 4, 2, 2, 7, 2, 3);
	testPoint(1, 1, 4, 2, 2, 7, 1.5, 5);
	testPoint(1, 1, 4, 2, 2, 7, 2, 7);
	testPoint(1, 1, 4, 2, 2, 7, 2, 6.99);
	testPoint(0, 0, 5, 0, 0, 5, 1, 1);
	testPoint(0, 0, 5, 0, 0, 5, -1, 1);
	testPoint(0, 0, 5, 0, 0, 5, 2, 0);
	testPoint(0, 0, 5, 0, 0, 5, 0, 2);
	testPoint(0, 0, 5, 0, 0, 5, 0, 0);
	testPoint(0, 0, 5, 0, 0, 5, 5, 0);
	testPoint(0, 0, 5, 0, 0, 5, 2, 2);
	
	return 0;
}
