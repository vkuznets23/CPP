/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:34:40 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/13 11:42:42 by viktoria         ###   ########.fr       */
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
        clock_t start = clock();
        test.sortVector();
        double diff1 = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;
        start = clock();
        test.sortDeque();
        double diff2 = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000.0;
        std::cout << "After: ";
        test.printVector();
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << diff1 << " us" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << std::fixed << diff2 << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}