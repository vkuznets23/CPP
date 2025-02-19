/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:57:46 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 10:29:50 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <class T> Array<T>::Array() : _n(0), _array(nullptr){};

template <class T> Array<T>::Array(unsigned int n) : _n(n), _array(new T[n]){};

template <class T> Array<T>::~Array()
{
    delete[] _array;
}

template <class T> Array<T>::Array(const Array<T> &o) : _n(o._n), _array(new T[o._n])
{
    for (unsigned int i = 0; i < _n; i++)
        _array[i] = o._array[i];
}

template <class T> Array<T> &Array<T>::operator=(const Array<T> &o)
{
    if (this != &o)
    {
        // allocate new memory
        T *newArray = new T[o._n];

        // copy elements
        for (size_t i = 0; i < o._n; i++)
        {
            newArray[i] = o._array[i];
        }

        delete[] _array;
        _array = newArray;
        _n = o._n;
    }
    return *this;
}

template <class T> unsigned int Array<T>::n() const
{
    return _n;
}

template <class T> T &Array<T>::operator[](unsigned int index)
{
    if (index >= _n)
        throw(std::out_of_range("Error: index out of bounds"));
    return (_array[index]);
}

template <class T> const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _n)
        throw(std::out_of_range("Error: index out of bounds"));
    return (_array[index]);
}