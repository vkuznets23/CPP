/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:50:14 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/05 10:31:55 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default name"), _signed(false), _signGrade(150), _execGrade(150) {std::cout << "Default Form constructor called" << std::endl;}

AForm::AForm(const AForm &origin) : _name(origin._name), _signed(origin._signed), _signGrade(origin._signGrade), _execGrade(origin._execGrade) { std::cout << "Copy Form constructor called" << std::endl; }

AForm::AForm(const std::string &name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Copy AForm constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &origin) {
    if (this != &origin) {
        _signed = origin._signed;
        // _name is a const string, so we can't assign it. No need to handle it here.
        // _signGrade and _execGrade are const, so they must be initialized in the constructor
        // and cannot be changed after object creation, so we don't assign them here.
    }
    return *this;
}

AForm::~AForm() {std::cout << "Default AForm destructor called" << std::endl; }

//getters
const std::string AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }
int	AForm::getSignGrade() const { return _signGrade; }
int	AForm::getExecGrade() const { return _execGrade; }

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high!";}
const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low!"; }
const char *AForm::NotSignedException::what() const throw() { return "Form not signed!";}


std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << "Form name: " << f.getName() << std::endl;
	out << "Signed: " << (f.getSigned() ? "true" : "false") << std::endl;
	out << "Sign Grade: " << f.getSignGrade() << std::endl;
	out << "Exec Grade: " << f.getExecGrade() << std::endl;
	return (out);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}
