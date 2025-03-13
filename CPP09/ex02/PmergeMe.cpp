/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:08:02 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/13 11:47:29 by viktoria         ###   ########.fr       */
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

void PmergeMe::sortVector() { PmergeMe::mergeSort(_vec); }
void PmergeMe::sortDeque() { PmergeMe::mergeSort(_deq); }

void PmergeMe::printVector() { PmergeMe::printContainer(_vec); }
void PmergeMe::printDeque() { PmergeMe::printContainer(_deq); }
