#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
   public:
       Intern();
       Intern(const Intern &origin);
       Intern &operator=(const Intern &origin);
       ~Intern();

       AForm *makeForm(const std::string &type, const std::string &target);
       static AForm *makeShrb(const std::string& target);
       static AForm *makeRobo(const std::string& target);
       static AForm *makePres(const std::string& target);
};