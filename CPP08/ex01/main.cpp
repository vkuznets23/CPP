/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:37 by vkuznets          #+#    #+#             */
/*   Updated: 2025/03/04 10:21:56 by vkuznets         ###   ########.fr       */
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
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {

        std::cout << "\n----- Another simple test -----" << std::endl;
        Span sp1 = Span(-1);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(4);
        sp1.addNumber(9);
        sp1.addNumber(11);
        std::cout << "shortest: " << sp1.shortestSpan() << std::endl;
        std::cout << "longest: " << sp1.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {

        std::cout << "\n----- Longer span than numbers -----" << std::endl;
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n----- Large numbers -----" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(std::numeric_limits<int>::max());
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(std::numeric_limits<int>::min());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n----- Large numbers2 -----" << std::endl;
        Span sp = Span(2);
        sp.addNumber(std::numeric_limits<int>::max());
        sp.addNumber(std::numeric_limits<int>::min());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n----- First element 0 -----" << std::endl;
        Span sp = Span(5);
        sp.addNumber(0);
        sp.addNumber(17);
        sp.addNumber(9);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
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
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n----- Empty Span -----" << std::endl;
        Span emptySpan(5);
        std::cout << "shortest: " << emptySpan.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
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
        std::cout << "longest: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- Random iterators -----" << std::endl;
    Span spanObject(10);
    try
    {
        spanObject.addNumber(1);
        spanObject.addNumber(2);
        spanObject.addNumber(4);
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- Normal -----" << std::endl;
    std::cout << "\nBefore:" << std::endl;
    spanObject.print();

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    try
    {
        spanObject.randomIterators(numbers.begin(), numbers.end());
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\nAfter:" << std::endl;
    spanObject.print();

    std::cout << "\n----- Start and end are the same -----" << std::endl;
    std::cout << "\nBefore:" << std::endl;
    spanObject.print();
    try
    {
        spanObject.randomIterators(numbers.end(), numbers.end());
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "After:" << std::endl;
    spanObject.print();

    std::cout << "\n----- End is before start -----" << std::endl;
    std::cout << "\nBefore:" << std::endl;
    spanObject.print();
    try
    {
        spanObject.randomIterators(numbers.end(), numbers.begin());
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "\nAfter:" << std::endl;
    spanObject.print();

    return 0;
}