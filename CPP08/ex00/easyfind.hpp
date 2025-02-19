/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:21:38 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 15:49:38 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

template <class T> typename T::iterator easyfind(T &container, int i);

#include "easyfind.tpp"