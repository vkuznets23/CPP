/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:14:22 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/11 13:14:39 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    try
    {
        RPN rpn_calc(av[1]);
        int res = rpn_calc.calculateExpression();
        std::cout << "Processed expression: " << res << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}