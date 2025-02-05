#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern constructor called" << std::endl; }

Intern::Intern(const Intern &origin) {
    (void)origin;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &origin) {
    (void)origin;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrb(const std::string &trgt) {return new ShrubberyCreationForm(trgt);}
AForm* Intern::makeRobo(const std::string &trgt) {return new RobotomyRequestForm(trgt);}
AForm* Intern::makePres(const std::string &trgt) {return new PresidentialPardonForm(trgt);}

AForm* Intern::makeForm(const std::string &type, const std::string &target) {
    int i = 0;
    std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* (*functions[3])(const std::string &target) = {
        &Intern::makeShrb,
        &Intern::makeRobo,
        &Intern::makePres
        };
    for(; i < 3 && type !=forms[i]; i++);
    std::cout << (i < 3 ? "intern created" + forms[i] : "no form created") << std::endl;
    return ((i < 3) ? functions[i](target) : 0);
}