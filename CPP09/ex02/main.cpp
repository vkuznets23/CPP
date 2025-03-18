/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:34:40 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/18 10:57:36 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cout << "Usage: ./PmergeMe n1 n2 n3 [...]" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe test(av + 1);
        std::cout << "Before: ";
        test.printVector();
        auto start_vec = std::chrono::high_resolution_clock::now();

        std::vector<int> vec;
        test.fill_vector(ac, av, vec);
        test.sort_vec(vec);

        auto end_vec = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end_vec - start_vec;
        double diff_in_microseconds = diff.count() * 1000000.0;

        std::cout << "After: ";
        test.updateVector(vec);
        test.printVector();
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(4) << diff_in_microseconds << " us" << std::endl;

        // std::cout << "Before: ";
        // test.printDeque();
        auto start_deq = std::chrono::high_resolution_clock::now();
        std::deque<int> deq;
        test.fill_deque(ac, av, deq);
        test.sort_deq(deq);

        auto end_deq = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end_deq - start_deq;
        double diff_in_microseconds2 = diff2.count() * 1000000.0;

        // std::cout << "After: ";
        test.updateDeque(deq);
        // test.printDeque();
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << std::fixed << std::setprecision(4) << diff_in_microseconds2 << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}