/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:06:23 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/11 13:14:01 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(std::string expression) : _expression(expression) {}
RPN::RPN(const RPN &o) : _expression(o._expression), _stack(o._stack) {}
// RPN &RPN::operator = (const RPN &original)
RPN::~RPN() {}

int RPN::calculateExpression()
{
    std::istringstream expr_stream(_expression);
    std::string token;
    std::string operators = "+-/*";
    while (std::getline(expr_stream, token, ' '))
    {
        if (token.empty())
            throw(std::runtime_error("Empty token in expression!"));
        else if (token.length() == 1 && operators.find(token) != std::string::npos)
            _performOperation(token);
        else if (token.length() == 1 && std::isdigit(token[0]))
            _stack.push(std::stoi(token));
        else
            throw(std::runtime_error("Invalid number: " + token + "!"));
    }
    if (_stack.size() != 1)
        throw(std::runtime_error("Invalid expression, more operands than operators!"));
    return _stack.top();
}

void RPN::_performOperation(std::string &token)
{
    if (_stack.size() < 2)
        throw(std::runtime_error("Invalid expression, operator with missing operands!"));
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (token == "+")
        _stack.push(a + b);
    else if (token == "-")
        _stack.push(a - b);
    else if (token == "/")
        _stack.push(a / b);
    else if (token == "*")
        _stack.push(a * b);
    else
        throw std::runtime_error("Unknown operator: " + token);
}
