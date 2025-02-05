#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
   private:
       const std::string _target;
   public:
       ShrubberyCreationForm();
       ShrubberyCreationForm(const std::string &target);
       ShrubberyCreationForm(const ShrubberyCreationForm &origin);
       ShrubberyCreationForm &operator=(const ShrubberyCreationForm &origin);
       ~ShrubberyCreationForm();

       void execute(const Bureaucrat &executor) const;
       class FileOpeningException;

};

class ShrubberyCreationForm::FileOpeningException: public std::exception
{
	public:
    		const char *what() const throw() override;
};
