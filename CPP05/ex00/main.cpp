/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:47:18 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/03 13:24:06 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "Test Valid Constructor" << std::endl;
    Bureaucrat b1("David Lynch", 100);
    std::cout << b1 << std::endl;  // Expected output: "David Lynch, bureaucrat grade 100"

    std::cout << "\nTest Invalid Constructor (grade too high)" << std::endl;
    try {
        Bureaucrat b1("David Lynch", 0);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl; // Output: "Grade is too high!"
    }

    std::cout << "\nTest Invalid Constructor (grade too low)" << std::endl;
    try {
        Bureaucrat b1("David Lynch", 160);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl; // Output: "Grade is too low!"
    }

    std::cout << "\nTest Copy Constructor" << std::endl;
    Bureaucrat b2("John Doe", 100);
    Bureaucrat b3(b2);
    std::cout << b3 << std::endl;  // Expected output: "John Doe, bureaucrat grade 100"

    std::cout << "\nTest Assignment Operator" << std::endl;
    Bureaucrat b4("Jane Smith", 150);
    b4 = b2;
    std::cout << b4 << std::endl;  // Expected output: "John Doe, bureaucrat grade 100"

    std::cout << "\nTest Incrementing Grade Beyond Limit" << std::endl;
    try {
        Bureaucrat b5("John Doe", 1);
        b5.incrementGrade();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;  // Output: "Grade is too high!"
    }

    std::cout << "\nTest Incrementing Grade" << std::endl;
    Bureaucrat b6("John Doe", 100);
    b6.incrementGrade();
    std::cout << b6 << std::endl;  // Expected output: "John Doe, bureaucrat grade 99"

    std::cout << "\nTest Decrementing Grade" << std::endl;
    Bureaucrat b7("John Doe", 100);
    b7.decrementGrade();
    std::cout << b7 << std::endl;  // Expected output: "John Doe, bureaucrat grade 101"

    std::cout << "\nTest Decrementing Grade Beyond Limit" << std::endl;
    try {
        Bureaucrat b8("John Doe", 150);
        b8.decrementGrade();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;  // Output: "Grade is too low!"
    }

    std::cout << "\nTest with Multiple Bureaucrats" << std::endl;
    try {
        Bureaucrat b9("John Doe", 50);
        Bureaucrat b10("Jane Smith", 200);  // Will throw exception
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;  // Output: "Grade is too low!"
    }
}
