#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PPF", 25, 5), _target("DefaultTarget") {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PPF", 25, 5), _target(target) {
    std::cout << "Parametarized PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin): AForm(origin), _target(origin._target) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &origin) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &origin) {
        // Call base class assignment operator
        AForm::operator=(origin);

        // _target is const, so we cannot assign it, so no action is needed here
        // _target will already be initialized in the constructor
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    //check if form i signed
	if (!this->getSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException(); // Bureaucrat's grade must be <= execGrade

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}