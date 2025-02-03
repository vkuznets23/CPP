/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:50:14 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/03 15:48:26 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default name"), _signed(false), _signGrade(150), _execGrade(150) {std::cout << "Default Form constructor called" << std::endl;}

Form::Form(const Form &origin) : _name(origin._name), _signed(origin._signed), _signGrade(origin._signGrade), _execGrade(origin._execGrade) { std::cout << "Copy Form constructor called" << std::endl; }

Form::Form(const std::string &name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Copy Form constructor called" << std::endl;
}

/*Form &Form::operator=(const Form &origin) {
	std::cout << "Copy Form assignment operator called" << std::endl;
}*/

Form::~Form() {std::cout << "Default Form destructor called" << std::endl; }

//getters
const std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecGrade() const {
	return _execGrade;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << "Form name: " << f.getName() << std::endl;
	out << "Signed: " << (f.getSigned() ? "true" : "false") << std::endl;
	out << "Sign Grade: " << f.getSignGrade() << std::endl;
	out << "Exec Grade: " << f.getExecGrade() << std::endl;
	return (out);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (_signed) {
		std::cout << "Form " << _name << " is already signed!" << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= _signGrade) {
		_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}
