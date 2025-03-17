/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:29:38 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/17 15:13:32 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <iomanip>
#include <deque>
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>

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

    void printVector();
    void printDeque();

    std::vector<std::pair<int, int>> make_pairs(std::vector<int> &arr);
    std::vector<int> extract_large_elements(const std::vector<std::pair<int, int>> &pairs);
    std::vector<int> extract_small_elements(const std::vector<std::pair<int, int>> &pairs);
    void fill_vector(int argc, char **argv, std::vector<int> &v);
    void recursive_sort(std::vector<int> &bigNumbers, std::vector<int> &excluded);
    void insert_remaining_elements(std::vector<int> &bigNumbers, const std::vector<int> &smallNumbers);
    void sort(std::vector<int> &arr);
    void updateVector(const std::vector<int> &sortedElements);

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