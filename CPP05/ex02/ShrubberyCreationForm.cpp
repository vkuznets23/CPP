#include "ShrubberyCreationForm.hpp"

#define TREE "\
        /\\\n\
       /**\\\n\
      /****\\\n\
     /******\\\n\
    /********\\\n\
   /**********\\\n\
  /************\\\n\
 /**************\\\n\
/****************\\\n\
       ||||\n\
       ||||\n"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("SCF", 145, 137), _target("Default target") {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("SCF", 145, 137), _target(target) {
    std::cout << "Parameterized ShrubberyCreationForm constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin): AForm(origin), _target(origin._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

/* ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &origin) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    // ?????
    return *this;
} */

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const char *ShrubberyCreationForm::FileOpeningException::what() const throw()
{
	return "Couldn't open file!";
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	
	std::ofstream outFile((_target + "_shrubbery").c_str());
	if (!outFile.is_open())
		throw ShrubberyCreationForm::FileOpeningException();
	outFile << TREE;
	outFile.close();
}