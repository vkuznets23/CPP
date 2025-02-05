#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RRF", 72, 45), _target("Default target") {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RRF", 72, 45), _target(target) {
    std::cout << "Parametarized RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin): AForm(origin), _target(origin._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

/* RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &origin) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    return *this;
} */

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::cout << "Drilling noises" << std::endl;

	std::srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;	
}