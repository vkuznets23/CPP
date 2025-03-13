/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:29:38 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/13 11:47:36 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <ctime>

class PmergeMe
{
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

public:
    PmergeMe();
    PmergeMe(char **av);
    PmergeMe(const PmergeMe &o);
    PmergeMe &operator=(const PmergeMe &o);
    ~PmergeMe();

    void sortVector();
    void sortDeque();
    void printVector();
    void printDeque();

    template <class T>
    static void mergeBack(T &container, T &left, T &right)
    {
        size_t i = 0, j = 0, k = 0;

        // compare elements from left and right and merge
        while (i < left.size() && j < right.size())
        {
            if (left[i] <= right[j])
                container[k++] = left[i++];
            else
                container[k++] = right[j++];
        }

        // if we still have elemets in left or right add
        while (i < left.size())
            container[k++] = left[i++];
        while (j < right.size())
            container[k++] = right[j++];
    }

    // split in 2 parts
    // sort left and right using recursion
    // merge them
    template <class T>
    static void mergeSort(T &container)
    {
        size_t mid = container.size() / 2;

        if (mid > 0)
        {
            T left(container.begin(), container.begin() + mid);
            T right(container.begin() + mid, container.end());

            mergeSort(left);
            mergeSort(right);
            mergeBack(container, left, right);
        }
    }

    template <class T>
    void printContainer(T &container)
    {
        for (int i : container)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};