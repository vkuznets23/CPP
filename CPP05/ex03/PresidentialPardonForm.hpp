#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
   private:
       const std::string _target;
   public:
       PresidentialPardonForm();
       PresidentialPardonForm(const std::string &target);
       PresidentialPardonForm(const PresidentialPardonForm &origin);
       PresidentialPardonForm &operator=(const PresidentialPardonForm &origin);
       ~PresidentialPardonForm();

       void execute(const Bureaucrat &executor) const;

};