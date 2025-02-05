#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
   private:
       const std::string _target;
   public:
       RobotomyRequestForm();
       RobotomyRequestForm(const std::string &target);
       RobotomyRequestForm(const RobotomyRequestForm &origin);
       RobotomyRequestForm &operator=(const RobotomyRequestForm &origin);
       ~RobotomyRequestForm();

        void execute(const Bureaucrat &executor) const;
};