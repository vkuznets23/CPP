/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:42:53 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/05 10:31:42 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		bool			_signed;
		const int		_signGrade;
		const int		_execGrade;
	public:
		AForm();
		AForm(const AForm &origin);
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm &operator=(const AForm &origin);
		virtual ~AForm();

		void	beSigned(const Bureaucrat &bureaucrat);

		//getters
		const std::string	getName() const;
		bool			getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException;
		class GradeTooLowException;
		class NotSignedException;
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

class	AForm::GradeTooHighException: public std::exception {
	public:
		//overriding a virtual function from the base class (std::exception)
		const char* what() const throw() override;
};

class	AForm::GradeTooLowException: public std::exception {
	public:
		const char* what() const throw() override;
};

class	AForm::NotSignedException : public std::exception
{
	public:
    		const char *what() const throw() override;
};
