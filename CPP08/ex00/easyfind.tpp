/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:35:37 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/19 15:53:32 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <class T> typename T::iterator easyfind(T &container, int i)
{
    typename T::iterator iter = find(container.begin(), container.end(), i);

    if (iter == container.end())
    {
        throw(std::out_of_range("Element " + std::to_string(i) + " was not found in the container"));
    }
    return iter;
}