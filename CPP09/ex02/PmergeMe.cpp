/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:02 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/17 12:07:59 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &o) : _vec(o._vec), _deq(o._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &o)
{
    if (this != &o)
    {
        _vec = o._vec;
        _deq = o._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **av)
{
    int i;
    char remain;

    // convert str to num
    while (*av)
    {
        std::istringstream token(*av);
        if (!(token >> i) || token >> remain)
            throw std::runtime_error("Failed to cast char* to int!");
        if (i <= 0)
            throw(std::runtime_error("Non positive int!"));
        _vec.push_back(i);
        _deq.push_back(i);
        av++;
    }
}

void PmergeMe::printVector() { PmergeMe::printContainer(_vec); }
void PmergeMe::printDeque() { PmergeMe::printContainer(_deq); }

void PmergeMe::fill_vector(int argc, char **argv, std::vector<int> &v)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        v.push_back(std::stoi(arg));
    }
}

std::vector<std::pair<int, int>> PmergeMe::make_pairs(std::vector<int> &arr)
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

std::vector<int> PmergeMe::extract_large_elements(const std::vector<std::pair<int, int>> &pairs)
{
    std::vector<int> large_elements;
    for (const auto &pair : pairs)
    {
        if (pair.second != -1) // ignore the fake element
            large_elements.push_back(pair.first);
    }
    return large_elements;
}

std::vector<int> PmergeMe::merge_sort(const std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    left = merge_sort(left);
    right = merge_sort(right);

    std::vector<int> result;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }

    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);

    return result;
}

void PmergeMe::insert_remaining_elements(std::vector<int> &sorted, const std::vector<int> &remaining)
{
    for (int element : remaining)
    {
        auto it = std::lower_bound(sorted.begin(), sorted.end(), element);
        sorted.insert(it, element);
    }
}

void PmergeMe::updateVector(const std::vector<int> &sortedElements)
{
    this->_vec = sortedElements;
}