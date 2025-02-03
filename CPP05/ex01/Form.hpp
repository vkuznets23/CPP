/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:42:53 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/03 15:53:01 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		bool			_signed;
		const int		_signGrade;
		const int		_execGrade;
	public:
		Form();
		Form(const Form &origin);
		Form(const std::string &name, int signGrade, int execGrade);
		Form &operator=(const Form &origin);
		~Form();

		void	beSigned(const Bureaucrat &bureaucrat);

		//getters
		const std::string	getName() const;
		bool			getSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		class GradeTooHighException;
		class GradeTooLowException;
};

std::ostream &operator<<(std::ostream &out, const Form &f);

class	Form::GradeTooHighException: public std::exception {
	public:
		const char* what() const noexcept override;
};

class	Form::GradeTooLowException: public std::exception {
	public:
		const char* what() const noexcept override;
};
