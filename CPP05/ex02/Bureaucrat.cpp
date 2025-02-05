/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:37:39 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/03 15:47:41 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default name"), _grade(150) {std::cout << "Default Bureaucrat constructor called" << std::endl;}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Parameterized Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &origin): _name(origin._name), _grade(origin._grade) {
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &origin) {
	std::cout << "Copy Bureaucrat assignment operator called" << std::endl;
	if (this != &origin) {
		_grade = origin._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

//increment / decrement functions
void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

//getters
const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};

//SIGN FORM
void Bureaucrat::signForm(AForm &form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e){
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
