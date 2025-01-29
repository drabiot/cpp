/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:58:05 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:50:34 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Shrubbery Creation", 145, 137) {
	this->_target = "Nobody";
	std::cout << GREEN "Create Shrubbery Creation Form" BASE_COLOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm("Shrubbery Creation", 145, 137) {
	this->_target = target;
	std::cout << GREEN "Create Shrubbery Creation Form" BASE_COLOR << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) : AForm("Shrubbery Creation", 145, 137) {
	*this = src;
	std::cout << GREEN "Shrubbery Creation Form Copy constructor called" BASE_COLOR << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = ( const ShrubberyCreationForm &rhs ) {
	std::cout << GREEN "Shrubbery Creation Form Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << YELLOW "Archived Shrubbery Creation Form" BASE_COLOR << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!(this->isSigned()))
			throw (AForm::NotSigned());
	if (executor.getGrade() > this->getExeGrade())
			throw (AForm::GradeTooLowException());
}	