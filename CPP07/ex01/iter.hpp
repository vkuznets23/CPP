/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:04:33 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/14 09:39:46 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void iter(T *arr, size_t length, void (*f)(T &el))
{

    for (size_t i = 0; i < length; i++)
        (*f)(arr[i]);
}

template <typename T> void iter(T *arr, size_t length, void (*f)(const T &el))
{

    for (size_t i = 0; i < length; i++)
        (*f)(arr[i]);
}

// A sample function to be applied on array elements
template <typename T> void printElement(const T &el)
{
    std::cout << el << " ";
}