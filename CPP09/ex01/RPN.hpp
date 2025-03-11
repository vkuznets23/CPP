/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:05:41 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/11 13:14:05 by viktoria         ###   ########.fr       */
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
    RPN(const RPN &original);
    ~RPN();

    RPN &operator=(const RPN &original);

    int calculateExpression();
};
