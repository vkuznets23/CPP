/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:43:21 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 15:52:30 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "Try if value exists" << std::endl;
    try
    {
        auto it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Try if value doesnt exists" << std::endl;
    try
    {
        auto it = easyfind(vec, 100);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}