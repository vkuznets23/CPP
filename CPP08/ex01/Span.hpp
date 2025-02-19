/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:58:45 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 16:26:21 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
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
};