/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:29 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/14 10:03:44 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T> class Array
{
  private:
    unsigned int _n;
    T *_array;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &o);
    Array<T> &operator=(const Array<T> &o);
    ~Array();

    // getter
    unsigned int n();

    // This function overloads the subscript operator ([]), allowing direct access to elements in the array.
    T &operator[](unsigned int index);
};

#include "Array.tpp"