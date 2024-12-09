/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:09:40 by vkuznets          #+#    #+#             */
/*   Updated: 2024/12/09 16:24:42 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(5), Fixed(0));
    Point c(Fixed(0), Fixed(5));
    Point p1(Fixed(1), Fixed(1));   // Inside
    Point p2(Fixed(-1), Fixed(1));  // Outside

    std::cout << "p1 inside triangle? " << (bsp(a, b, c, p1) ? "Yes" : "No") << std::endl;
    std::cout << "p2 inside triangle? " << (bsp(a, b, c, p2) ? "Yes" : "No") << std::endl;

    return 0;
}
