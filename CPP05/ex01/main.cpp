/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:47:18 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/03 15:55:56 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "\nTest Valid Form Constructor" << std::endl;
    try {
        Form form1("Tax Form", 50, 100);
        std::cout << form1 << std::endl;  // Expected output: form details with name, grades and signed status
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest Invalid Form Constructor (grade too high)" << std::endl;
    try {
        Form form1("Tax Form", 0, 100);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;  // Expected output: "Grade is too high!"
    }

    std::cout << "\nTest Invalid Form Constructor (grade too low)" << std::endl;
    try {
        Form form1("Tax Form", 151, 100);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;  // Expected output: "Grade is too low!"
    }

    std::cout << "\nTest Bureaucrat Signing Form with Sufficient Grade" << std::endl;
    try {
        Bureaucrat b1("John Doe", 50);  // High enough grade to sign
        Form form1("Tax Form", 50, 100);
        b1.signForm(form1);  // Expected output: "John Doe signed Tax Form"
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest Bureaucrat Signing Form with Insufficient Grade" << std::endl;
    try {
        Bureaucrat b1("John Doe", 150);  // Too low grade to sign
        Form form1("Tax Form", 50, 100);
        b1.signForm(form1);  // Expected output: "John Doe couldn’t sign Tax Form because grade is too low!"
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest Form Already Signed" << std::endl;
    try {
        Bureaucrat b1("John Doe", 50);
        Form form1("Tax Form", 50, 100);
        b1.signForm(form1);
        b1.signForm(form1);  // Expected output: "John Doe signed Tax Form"
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest Form Signing with Exception" << std::endl;
    try {
        Bureaucrat b1("John Doe", 50);
        Form form1("Tax Form", 50, 100);
        b1.signForm(form1);  // Expected output: "John Doe signed Tax Form"
        Bureaucrat b2("Jane Smith", 151);  // Too low grade
        b2.signForm(form1);  // Expected output: "Jane Smith couldn’t sign Tax Form because grade is too low!"
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nTest Form Sign with Multiple Bureaucrats" << std::endl;
    try {
        Bureaucrat b1("John Doe", 50);
        Bureaucrat b2("Jane Smith", 151);  // Low grade
        Form form1("Tax Form", 50, 100);
        b1.signForm(form1);  // Expected output: "John Doe signed Tax Form"
        b2.signForm(form1);  // Expected output: "Jane Smith couldn’t sign Tax Form because grade is too low!"
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
