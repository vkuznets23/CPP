/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorSorting.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:34:40 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/18 10:20:47 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::fill_vector(int argc, char **argv, std::vector<int> &v)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        v.push_back(std::stoi(arg));
    }
}

std::vector<std::pair<int, int>> PmergeMe::make_pairs_vec(std::vector<int> &arr)
{
    std::vector<std::pair<int, int>> pairs;
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

std::vector<int> PmergeMe::extract_large_element_vec(const std::vector<std::pair<int, int>> &pairs)
{
    std::vector<int> large_elements;
    for (const auto &pair : pairs)
    {
        if (pair.second != -1)
            large_elements.push_back(pair.first);
    }

    return large_elements;
}

std::vector<int> PmergeMe::extract_small_elements_vec(const std::vector<std::pair<int, int>> &pairs)
{
    std::vector<int> small_elements;

    for (const auto &pair : pairs)
    {
        if (pair.second != -1)
            small_elements.push_back(pair.second);
        if (pair.second == -1)
            small_elements.push_back(pair.first);
    }

    return small_elements;
}

void PmergeMe::insert_remaining_elements_vec(std::vector<int> &bigNumbers, const std::vector<int> &smallNumbers)
{
    for (int small : smallNumbers)
    {
        auto it = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), small);
        bigNumbers.insert(it, small);
    }
}

void PmergeMe::sort_vec(std::vector<int> &arr)
{
    if (arr.size() == 1)
        return;

    std::vector<std::pair<int, int>> pairs = make_pairs_vec(arr);
    std::vector<int> bigNumbers = extract_large_element_vec(pairs);
    std::vector<int> smallNumbers = extract_small_elements_vec(pairs);

    sort_vec(bigNumbers);
    insert_remaining_elements_vec(bigNumbers, smallNumbers);

    arr = bigNumbers;
}

void PmergeMe::updateVector(const std::vector<int> &sortedElements)
{
    this->_vec = sortedElements;
}