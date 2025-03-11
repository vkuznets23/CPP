/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:33:52 by viktoria          #+#    #+#             */
/*   Updated: 2025/03/03 10:29:02 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <limits>
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

    std::cout << "\n----- Empty Stack Test -----" << std::endl;
    MutantStack<int> emptyStack;
    std::cout << "Is stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;

    std::cout << "\n----- Large Number Test -----" << std::endl;
    MutantStack<long long> largeStack;
    largeStack.push(std::numeric_limits<long long>::max()); // 9223372036854775807
    largeStack.push(std::numeric_limits<long long>::min()); // -9223372036854775808

    std::cout << "Stack contents: ";
    for (auto it = largeStack.begin(); it != largeStack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}