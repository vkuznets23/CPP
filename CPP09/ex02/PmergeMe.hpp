/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:29:38 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/18 10:25:26 by viktoria         ###   ########.fr       */
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

    // vector sorting functions
    std::vector<std::pair<int, int>> make_pairs_vec(std::vector<int> &arr);
    std::vector<int> extract_large_element_vec(const std::vector<std::pair<int, int>> &pairs);
    std::vector<int> extract_small_elements_vec(const std::vector<std::pair<int, int>> &pairs);
    void fill_vector(int ac, char **av, std::vector<int> &v);
    void recursive_sort_vec(std::vector<int> &bigNumbers, std::vector<int> &excluded);
    void insert_remaining_elements_vec(std::vector<int> &bigNumbers, const std::vector<int> &smallNumbers);
    void sort_vec(std::vector<int> &arr);
    void updateVector(const std::vector<int> &sortedElements);

    // deque sorting functions
    void fill_deque(int argc, char **argv, std::deque<int> &v);
    std::deque<std::pair<int, int>> make_pairs_deq(std::deque<int> &arr);
    std::deque<int> extract_large_elements_deq(const std::deque<std::pair<int, int>> &pairs);
    std::deque<int> extract_small_elements_deq(const std::deque<std::pair<int, int>> &pairs);
    void insert_remaining_elements_deq(std::deque<int> &bigNumbers, const std::deque<int> &smallNumbers);
    void sort_deq(std::deque<int> &arr);
    void updateDeque(const std::deque<int> &sortedElements);

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