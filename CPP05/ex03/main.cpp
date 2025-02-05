/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:27:52 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/05 10:27:57 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Intern someRandomIntern;  // Create an Intern object

        // Test valid form creation using Intern
        std::cout << "\nCreating ShrubberyCreationForm...\n";
        AForm *form1 = someRandomIntern.makeForm("ShrubberyCreationForm", "Garden");
        if (form1) {
            std::cout << "Form created successfully!" << std::endl;
            Bureaucrat boss("Boss", 1);  // Grade 1 Bureaucrat
            boss.signForm(*form1);  // Sign the form
            boss.executeForm(*form1);  // Execute the form
            delete form1;  // Clean up memory
        }

        std::cout << "\nCreating RobotomyRequestForm...\n";
        // Test valid form creation using Intern
        AForm *form2 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
        if (form2) {
            std::cout << "Form created successfully!" << std::endl;
            Bureaucrat boss("Boss", 1);  // Grade 1 Bureaucrat
            boss.signForm(*form2);  // Sign the form
            boss.executeForm(*form2);  // Execute the form
            delete form2;  // Clean up memory
        }

        std::cout << "\nCreating PresidentialPardonForm...\n";
        // Test valid form creation using Intern
        AForm *form3 = someRandomIntern.makeForm("PresidentialPardonForm", "John Doe");
        if (form3) {
            std::cout << "Form created successfully!" << std::endl;
            Bureaucrat boss("Boss", 1);  // Grade 1 Bureaucrat
            boss.signForm(*form3);  // Sign the form
            boss.executeForm(*form3);  // Execute the form
            delete form3;  // Clean up memory
        }

        std::cout << "\nCreating invalid form...\n";
        // Test invalid form type
        AForm *form4 = someRandomIntern.makeForm("NonExistentForm", "Unknown");
        if (!form4) {
            std::cout << "No form created due to invalid type!" << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}