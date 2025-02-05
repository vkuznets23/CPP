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
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create a Bureaucrat with a sufficient grade to execute the form
        Bureaucrat boss("Boss", 1);  // Grade 1 (highest)
        std::cout << boss << std::endl;

        // Test ShrubberyCreationForm
        {
            // Create a ShrubberyCreationForm targeting "Home"
            ShrubberyCreationForm shrubberyForm("Home");
            std::cout << "ShrubberyCreationForm created for target: Home" << std::endl;

            // Sign the form
            boss.signForm(shrubberyForm);

            // Execute the form (this should create a file "Home_shrubbery" with the tree ASCII)
            boss.executeForm(shrubberyForm);
            std::cout << "Shrubbery created successfully!" << std::endl;
        }

        std::cout << std::endl; // Add some space between tests

        // Test RobotomyRequestForm
        {
            // Create a RobotomyRequestForm targeting "Robot"
            RobotomyRequestForm robotomyForm("Robot");
            std::cout << "RobotomyRequestForm created for target: Robot" << std::endl;

            // Sign the form
            boss.signForm(robotomyForm);

            // Execute the form (this will simulate a robotomy attempt)
            boss.executeForm(robotomyForm);
            std::cout << "Robotomy attempt finished!" << std::endl;
        }

        std::cout << std::endl; // Add some space between tests

        // Test PresidentialPardonForm
        {
            // Create a PresidentialPardonForm targeting "John Doe"
            PresidentialPardonForm pardonForm("John Doe");
            std::cout << "PresidentialPardonForm created for target: John Doe" << std::endl;

            // Sign the form
            boss.signForm(pardonForm);

            // Execute the form (this should print a pardon message)
            boss.executeForm(pardonForm);
            std::cout << "Presidential pardon granted!" << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}


