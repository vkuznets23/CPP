/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:05:41 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/13 11:50:50 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

class RPN
{
private:
    std::string _expression;
    std::stack<int> _stack;
    void _performOperation(std::string &token);

public:
    RPN();
    RPN(std::string expression);
    RPN(const RPN &o);
    ~RPN();

    RPN &operator=(const RPN &o);

    int calculateExpression();
};
