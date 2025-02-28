/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:58:45 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/28 10:25:21 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Span
{
  private:
    unsigned int _n;
    std::vector<int> _vec;

  public:
    Span();
    Span(unsigned int N);
    Span(const Span &o);
    Span &operator=(const Span &o);
    ~Span();

    void addNumber(int num);

    unsigned int shortestSpan();
    unsigned int longestSpan();

    void print(); // to print numbers

    template <typename Iterator> void randomIterators(Iterator begin, Iterator end)
    {
        if (begin == end)
        {
            std::cout << "Warning: Attempting to insert an empty range => nothing changes" << std::endl;
            return;
        }
        // if (begin > end)
        if (std::distance(begin, end) < 0)
        {
            throw std::invalid_argument("Invalid iterator range: 'begin' is after 'end'");
        }
        if (_vec.size() + std::distance(begin, end) > _n)
        {
            throw std::overflow_error("Span will exceed maximum size");
        }
        _vec.insert(_vec.end(), begin, end);
    }
};