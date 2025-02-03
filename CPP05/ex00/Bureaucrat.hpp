/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:24:48 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/03 13:26:20 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <exception>

class	Bureaucrat {
	private:
		const std::string	_name;
		int			_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &origin);
		Bureaucrat &operator=(const Bureaucrat &origin);
		~Bureaucrat();
		
		//exception functions 
		class	GradeTooHighException;
		class	GradeTooLowException;

		// Functions to increment or decrement grade
		void incrementGrade();
		void decrementGrade();
		
		//getters
		const	std::string getName() const;
		int	getGrade() const;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

class	Bureaucrat::GradeTooHighException: public std::exception {
	public:
		const char* what() const throw();
};

class	Bureaucrat::GradeTooLowException: public std::exception {
	public:
		const char* what() const throw();
};
