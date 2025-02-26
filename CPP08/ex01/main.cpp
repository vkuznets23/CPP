/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:37 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/26 16:00:30 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {

        std::cout << "----- Given test -----" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "longest: " << sp.longestSpan() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {

        std::cout << "\n----- Another simple test -----" << std::endl;
        Span sp1 = Span(8);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(4);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "shortest: " << sp1.shortestSpan() << std::endl;
        std::cout << "longest: " << sp1.longestSpan() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {

        std::cout << "\n----- Not enough nums -----" << std::endl;
        Span sp2 = Span(1);
        sp2.addNumber(100);
        std::cout << "shortest: " << sp2.shortestSpan() << std::endl;
        std::cout << "longest: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n----- 10K nums -----" << std::endl;
        Span sp3 = Span(10000);
        for (int i = 1; i <= 10000; i++)
        {
            sp3.addNumber(i);
        }
        std::cout << "shortest: " << sp3.shortestSpan() << std::endl;
        std::cout << "shortest: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- Random iterators -----" << std::endl;
    Span spanObject(100);
    spanObject.addNumber(1);
    spanObject.addNumber(2);
    spanObject.addNumber(4);
    std::cout << "\nBefore:" << std::endl;
    spanObject.print();

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    try
    {
        spanObject.randomIterators(numbers.begin(), numbers.end());
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\nAfter:" << std::endl;
    spanObject.print();

    std::cout << "\nBefore:" << std::endl;
    spanObject.print();
    try
    {
        spanObject.randomIterators(numbers.end(), numbers.end());
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "After:" << std::endl;
    spanObject.print();

    std::cout << "\nBefore:" << std::endl;
    spanObject.print();
    try
    {
        spanObject.randomIterators(numbers.end(), numbers.begin());
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\nAfter:" << std::endl;
    spanObject.print();

    return 0;
}