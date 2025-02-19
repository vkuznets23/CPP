/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:29 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 10:14:17 by vkuznets         ###   ########.fr       */
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
    unsigned int n() const;

    // This function overloads the subscript operator ([]), allowing direct access to elements in the array.
    T &operator[](unsigned int index);

    const T &operator[](unsigned int index) const; // Subscript operator (read-only)
};

#include "Array.tpp"