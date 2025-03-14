/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:44:28 by viktoria          #+#    #+#             */
/*   Updated: 2025/02/13 19:44:28 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"

// uintptr_t is an unsigned integer type defined in the C++ standard library (in the <cstdint> header)
// that is guaranteed to be large enough to store a pointer (it can hold the value of any memory address)
class Serializer
{
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:
    Serializer() = delete;
    Serializer(const Serializer &origin) = delete;
    Serializer &operator=(const Serializer &origin) = delete;
    ~Serializer() = delete;
};
