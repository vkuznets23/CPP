/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:18:58 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 16:30:57 by vkuznets         ###   ########.fr       */
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
}
