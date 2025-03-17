/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:34:40 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/17 13:57:37 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Usage: ./PmergeMe n1 n2 n3 [...]" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe test(av + 1);
        std::cout << "Before: ";
        test.printVector();
        auto start = std::chrono::high_resolution_clock::now();

        std::vector<int> vec;
        test.fill_vector(ac, av, vec);
        test.sort(vec);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        double diff_in_microseconds = diff.count() * 1000000.0;

        std::cout << "After: ";
        test.updateVector(vec);
        test.printVector();

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(4) << diff_in_microseconds << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}