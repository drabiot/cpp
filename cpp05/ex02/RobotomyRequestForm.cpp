/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:58:00 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/30 09:58:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("Robotomy Request", 72, 45) {
	this->_target = "Nobody";
	std::cout << GREEN "Create Robotomy Request Form" BASE_COLOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("Robotomy Request", 72, 45) {
	this->_target = target;
	std::cout << GREEN "Create Robotomy Request Form" BASE_COLOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm("Robotomy Request", 72, 45) {
	*this = src;
	std::cout << GREEN "Robotomy Request Form Copy constructor called" BASE_COLOR << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator = ( const RobotomyRequestForm &rhs ) {
	std::cout << GREEN "Robotomy Request Form Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << YELLOW "Archived Robotomy Request Form" BASE_COLOR << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!(this->isSigned()))
			throw (AForm::NotSigned());
	if (executor.getGrade() > this->getExeGrade())
			throw (AForm::GradeTooLowException());
	std::srand(std::time(NULL));

	int	random = std::rand();

	if (random % 2 == 0)
		std::cout << CYAN "*brzzzzzz brrrzzzzzz* Congrats " MAGENTA << this->_target << CYAN ", the robotomy was successful!" BASE_COLOR << std::endl;
	else
		std::cout << CYAN "*brzzzzzz brrrzzzzzz* Sorry " MAGENTA << this->_target << CYAN ", the robotomy failled..." BASE_COLOR << std::endl;
}	