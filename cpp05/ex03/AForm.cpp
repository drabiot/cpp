/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:20 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/31 14:04:07 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unknow AForm"), _signGrade(150), _execGrade(150) {
	this->_signed = false;
	std::cout << GREEN "a new unknow Aform has just arrived. For now everybody can sign and execute this Aform" BASE_COLOR << std::endl;
}

AForm::AForm( const std::string &name, const size_t &signGrade, const size_t &execGrade ) : _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw(AForm::GradeTooHightException());
	if (this->_signGrade > 150 || this->_execGrade >150)
		throw(AForm::GradeTooLowException());
	this->_signed = false;
	std::cout << GREEN "The Aform: " MAGENTA << getName() << GREEN " has just arrived. You need to be Grade " MAGENTA << getSignGrade() << GREEN " to sign it & garde " MAGENTA << getExeGrade() << GREEN " to execute it" BASE_COLOR << std::endl; 
}

AForm::AForm( const AForm &src ) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade) {
	*this = src;
	std::cout << GREEN "AForm Copy constructor called" BASE_COLOR << std::endl;
}

AForm &AForm::operator = ( const AForm &rhs ) {
	std::cout << GREEN "AForm Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_signed = rhs._signed;
	const_cast<size_t &>(this->_signGrade) = rhs._signGrade;
	const_cast<size_t &>(this->_execGrade) = rhs._execGrade;
	return (*this);
}

AForm::~AForm() {
	std::cout << YELLOW "The Aform: " MAGENTA << getName() << YELLOW " is finnaly archived" BASE_COLOR << std::endl;
}

const std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::isSigned() const {
 return (this->_signed);
}

size_t	AForm::getSignGrade() const {
	return (this->_signGrade);
}

size_t	AForm::getExeGrade() const {
	return (this->_execGrade);
}

void	AForm::beSigned( Bureaucrat &bureaucrat ) {
	if (this->isSigned())
		throw (AForm::AlreadySigned());
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw (AForm::GradeTooLowException());
	this->_signed = true;
}

const char	*AForm::GradeTooHightException::what() const throw () {
	return (RED "Grade too hight..." BASE_COLOR);
}

const char	*AForm::GradeTooLowException::what() const throw () {
	return (RED "Grade too low..." BASE_COLOR);
}

const char	*AForm::AlreadySigned::what() const throw () {
	return (RED "Form already signed..." BASE_COLOR);
}

const char	*AForm::NotSigned::what() const throw () {
	return (RED "Form not signed..." BASE_COLOR);
}

const char	*AForm::FileError::what() const throw () {
	return (RED "Couldn't open the file..." BASE_COLOR);
}

std::ostream	&operator << (std::ostream &os, const AForm &AForm) {
	if (AForm.isSigned())
		os << CYAN "Signed Form: " MAGENTA << AForm.getName() << CYAN " can be signed by Bureaucrat worth Grade " MAGENTA << AForm.getSignGrade() << CYAN " & execute by Bureaucrat worth Grade" MAGENTA << AForm.getExeGrade() << BASE_COLOR;
	else
		os << CYAN "Unsigned Form: " MAGENTA << AForm.getName() << CYAN " can be signed by Bureaucrat worth Grade " MAGENTA << AForm.getSignGrade() << CYAN " & execute by Bureaucrat worth Grade" MAGENTA << AForm.getExeGrade() << BASE_COLOR;
	return (os);
}
