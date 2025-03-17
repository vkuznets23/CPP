/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:02 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/17 15:34:58 by viktoria         ###   ########.fr       */
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
        if (pair.second != -1)
            large_elements.push_back(pair.first);
    }

    // std::cout << "Large elements: ";
    // for (int num : large_elements)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;
    return large_elements;
}

std::vector<int> PmergeMe::extract_small_elements(const std::vector<std::pair<int, int>> &pairs)
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

void PmergeMe::insert_remaining_elements(std::vector<int> &bigNumbers, const std::vector<int> &smallNumbers)
{
    for (int small : smallNumbers)
    {
        auto it = std::lower_bound(bigNumbers.begin(), bigNumbers.end(), small);
        bigNumbers.insert(it, small);
    }
}

// void PmergeMe::recursive_sort(std::vector<int> &bigNumbers, std::vector<int> &small_elements)
// {
//     if (bigNumbers.size() == 1)
//         return;

//     std::vector<std::pair<int, int>> pairs = make_pairs(bigNumbers);
//     std::vector<int> newBigNumbers = extract_large_elements(pairs);
//     std::vector<int> smallNumbers = extract_small_elements(pairs);

//     small_elements.insert(small_elements.end(), smallNumbers.begin(), smallNumbers.end());

//     recursive_sort(newBigNumbers, small_elements);

//     bigNumbers = newBigNumbers;
// }

void PmergeMe::sort(std::vector<int> &arr)
{
    if (arr.size() == 1)
        return;

    std::vector<std::pair<int, int>> pairs = make_pairs(arr);
    std::vector<int> bigNumbers = extract_large_elements(pairs);
    std::vector<int> smallNumbers = extract_small_elements(pairs);

    // recursive_sort(bigNumbers, smallNumbers);
    sort(bigNumbers);
    std::cout << "bignumber: ";
    printContainer(bigNumbers);
    std::cout << "smallnum: ";
    printContainer(smallNumbers);

    insert_remaining_elements(bigNumbers, smallNumbers);

    arr = bigNumbers;
}

void PmergeMe::updateVector(const std::vector<int> &sortedElements)
{
    this->_vec = sortedElements;
}