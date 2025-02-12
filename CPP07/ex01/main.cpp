/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:10:57 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/12 11:20:44 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    double doubleArray[4] = {1.1, 2.2, 3.3, 4.4};
    char charArray[4] = {'a', 'b', 'c', 'd'};
    std::string stringArr[3] = {"Hope", "this", "passes"};
    bool boolArr[2] = {true, false};

    iter<int>(intArray, 5, &printElement);
    std::cout << std::endl;

    iter<double>(doubleArray, 4, &printElement);
    std::cout << std::endl;

    iter<char>(charArray, 4, &printElement);
    std::cout << std::endl;

    iter<std::string>(stringArr, 3, &printElement);
    std::cout << std::endl;

    iter<bool>(boolArr, 2, &printElement);
    std::cout << std::endl;

    return 0;
}