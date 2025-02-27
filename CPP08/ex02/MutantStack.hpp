/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:15:50 by viktoria          #+#    #+#             */
/*   Updated: 2025/02/27 17:30:32 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

// inherit form std::stack so we keep all features of standart stack
template <class T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack &original);
    MutantStack &operator=(const MutantStack &o);
    ~MutantStack();

    // iterators
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin();
    reverse_iterator rend();

    // only reading access
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator cbegin() const;
    const_iterator cend() const;

    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};

#include "MutantStack.tpp"
