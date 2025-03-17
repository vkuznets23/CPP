/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:34:40 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/17 12:07:42 by viktoria         ###   ########.fr       */
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
        std::vector<std::pair<int, int>> pairs = test.make_pairs(vec);

        // std::cout << "Pairs: ";
        // for (const auto &pair : pairs)
        // {
        //     std::cout << "(" << pair.first << ", " << pair.second << ") ";
        // }
        // std::cout << std::endl;

        std::vector<int> large_elements = test.extract_large_elements(pairs);
        large_elements = test.merge_sort(large_elements);

        // std::cout << "Sorted large elements: ";
        // test.printContainer(large_elements);

        std::vector<int> remaining_elements;
        for (const auto &pair : pairs)
        {
            if (pair.second != -1)
                remaining_elements.push_back(pair.second);
            if (pair.second == -1)
                remaining_elements.push_back(pair.first);
        }
        remaining_elements = test.merge_sort(remaining_elements);

        // std::cout << "Sorted remaining elements: ";
        // test.printContainer(remaining_elements);

        test.insert_remaining_elements(large_elements, remaining_elements);

        // std::cout << "Final sorted list: ";
        // test.printContainer(large_elements);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        double diff_in_microseconds = diff.count() * 1000000.0;

        test.updateVector(large_elements);

        std::cout << "After: ";
        test.printVector();

        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << std::fixed << std::setprecision(4) << diff_in_microseconds << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}