/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:57:52 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:58:43 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("Presidential Pardon", 25, 5) {
	this->_target = "Nobody";
	std::cout << GREEN "Create Presidential Pardon Form" BASE_COLOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &target ) : AForm("Presidential Pardon", 25, 5) {
	this->_target = target;
	std::cout << GREEN "Create Presidential Pardon Form" BASE_COLOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm("Presidential Pardon", 25, 5) {
	*this = src;
	std::cout << GREEN "Presidential Pardon Form Copy constructor called" BASE_COLOR << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator = ( const PresidentialPardonForm &rhs ) {
	std::cout << GREEN "Presidential Pardon Form Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << YELLOW "Archived Presidential Pardon Form" BASE_COLOR << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!(this->isSigned()))
			throw (AForm::NotSigned());
	if (executor.getGrade() > this->getExeGrade())
			throw (AForm::GradeTooLowException());
	std::cout << CYAN "Zaphod Beeblebrox pardoned " MAGENTA << this->_target << BASE_COLOR << std::endl;
}	
