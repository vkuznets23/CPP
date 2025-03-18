/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeSorting.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:34:40 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/18 10:25:34 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::fill_deque(int argc, char **argv, std::deque<int> &v)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        v.push_back(std::stoi(arg));
    }
}

std::deque<std::pair<int, int>> PmergeMe::make_pairs_deq(std::deque<int> &arr)
{
    std::deque<std::pair<int, int>> pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
            pairs.emplace_back(arr[i], arr[i + 1]);
        else
            pairs.emplace_back(arr[i + 1], arr[i]);
    }
    if (arr.size() % 2 != 0)
        pairs.emplace_back(arr.back(), -1);

    return pairs;
}

std::deque<int> PmergeMe::extract_large_elements_deq(const std::deque<std::pair<int, int>> &pairs)
{
    std::deque<int> large_elements;
    for (const auto &pair : pairs)
    {
        if (pair.second != -1)
            large_elements.push_back(pair.first);
    }

    return large_elements;
}

std::deque<int> PmergeMe::extract_small_elements_deq(const std::deque<std::pair<int, int>> &pairs)
{
    std::deque<int> small_elements;

    for (const auto &pair : pairs)
    {
        if (pair.second != -1)
            small_elements.push_back(pair.second);
        if (pair.second == -1)
            small_elements.push_back(pair.first);
    }

    return small_elements;
}

void PmergeMe::insert_remaining_elements_deq(std::deque<int> &bigNumbers, const std::deque<int> &smallNumbers)
{
    for (int small : smallNumbers)
    {
        auto it = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), small);
        bigNumbers.insert(it, small);
    }
}

void PmergeMe::sort_deq(std::deque<int> &arr)
{
    if (arr.size() == 1)
        return;

    std::deque<std::pair<int, int>> pairs = make_pairs_deq(arr);
    std::deque<int> bigNumbers = extract_large_elements_deq(pairs);
    std::deque<int> smallNumbers = extract_small_elements_deq(pairs);

    sort_deq(bigNumbers);
    insert_remaining_elements_deq(bigNumbers, smallNumbers);

    arr = bigNumbers;
}

void PmergeMe::updateDeque(const std::deque<int> &sortedElements)
{
    this->_deq = sortedElements;
}