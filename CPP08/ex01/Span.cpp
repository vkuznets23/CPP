/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:18:58 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/26 16:00:04 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {};

Span::Span(unsigned int N) : _n(N) {};

Span::Span(const Span &o) : _n(o._n), _vec(o._vec) {};

//????? add vector thingy
Span &Span::operator=(const Span &o)
{
    if (this != &o)
    {
        _n = o._n;
    }
    return *this;
}

Span::~Span() {};

void Span::addNumber(int num)
{
    if (_vec.size() >= _n)
    {
        throw std::out_of_range("Can't hold more numbers");
    }
    _vec.push_back(num);
}

unsigned int Span::shortestSpan()
{
    if (_vec.size() < 2)
        throw(std::runtime_error("Less than 2 nums -> shortest span doesn't exist"));

    std::sort(_vec.begin(), _vec.end());

    unsigned int minDiff = std::numeric_limits<unsigned int>::max(); // start from the min possible diff
    for (size_t i = 1; i < _vec.size(); ++i)
    {
        unsigned int diff = _vec[i] - _vec[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

unsigned int Span::longestSpan()
{
    if (_vec.size() < 2)
        throw(std::runtime_error("Less than 2 nums -> longest span doesn't exist"));
    auto [minIt, maxIt] = std::minmax_element(_vec.begin(), _vec.end());
    return *maxIt - *minIt;
}

void Span::print()
{
    for (int i : _vec)
        std::cout << i << " ";
    std::cout << "\n";
}
