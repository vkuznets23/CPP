/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:33:52 by viktoria          #+#    #+#             */
/*   Updated: 2025/02/27 17:44:12 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "----- original main -----" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "----- list main -----" << std::endl;
    std::list<int> mstack1;
    mstack1.push_back(5);
    mstack1.push_back(17);
    std::cout << mstack1.back() << std::endl; // Equivalent to top() in stack
    mstack1.pop_back();
    std::cout << mstack1.size() << std::endl;

    mstack1.push_back(3);
    mstack1.push_back(5);
    mstack1.push_back(737);
    mstack1.push_back(0);

    std::list<int>::iterator it_list = mstack1.begin();
    std::list<int>::iterator ite_list = mstack1.end();

    ++it_list;
    --it_list;

    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }

    std::list<int> s1(mstack1); // Copy constructor check

    return 0;
}