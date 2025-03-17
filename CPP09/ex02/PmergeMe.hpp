/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:29:38 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/17 12:05:00 by viktoria         ###   ########.fr       */
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

    static std::vector<std::pair<int, int>> make_pairs(std::vector<int> &arr);
    void fill_vector(int argc, char **argv, std::vector<int> &v);
    static std::vector<int> extract_large_elements(const std::vector<std::pair<int, int>> &pairs);
    static std::vector<int> merge_sort(const std::vector<int> &arr);
    static void insert_remaining_elements(std::vector<int> &sorted, const std::vector<int> &remaining);
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