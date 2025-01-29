/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:20 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:22:33 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Unknow Form"), _signGrade(150), _execGrade(150) {
	this->_signed = false;
	std::cout << GREEN "a new unknow form has just arrived. For now everybody can sign and execute this form" BASE_COLOR << std::endl;
}

Form::Form( const std::string &name, const size_t &signGrade, const size_t &execGrade ) : _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw(Form::GradeTooHightException());
	if (this->_signGrade > 150 || this->_execGrade >150)
		throw(Form::GradeTooLowException());
	this->_signed = false;
	std::cout << GREEN "The form: " MAGENTA << getName() << GREEN " has just arrived. You need to be Grade " MAGENTA << getSignGrade() << GREEN " to sign it & garde " MAGENTA << getExeGrade() << GREEN " to execute it" BASE_COLOR << std::endl; 
}

Form::Form( const Form &src ) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade) {
	*this = src;
	std::cout << GREEN "Form Copy constructor called" BASE_COLOR << std::endl;
}

Form &Form::operator = ( const Form &rhs ) {
	std::cout << GREEN "Form Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_signed = rhs._signed;
	const_cast<size_t &>(this->_signGrade) = rhs._signGrade;
	const_cast<size_t &>(this->_execGrade) = rhs._execGrade;
	return (*this);
}

Form::~Form() {
	std::cout << YELLOW "The form: " MAGENTA << getName() << YELLOW " is finnaly archived" BASE_COLOR << std::endl;
}

const std::string	Form::getName() const {
	return (this->_name);
}

bool	Form::isSigned() const {
 return (this->_signed);
}

size_t	Form::getSignGrade() const {
	return (this->_signGrade);
}

size_t	Form::getExeGrade() const {
	return (this->_execGrade);
}

void	Form::beSigned( Bureaucrat &bureaucrat ) {
	if (this->isSigned())
		throw (Form::AlreadySigned());
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

const char	*Form::GradeTooHightException::what() const throw () {
	return (RED "Grade too hight..." BASE_COLOR);
}

const char	*Form::GradeTooLowException::what() const throw () {
	return (RED "Grade too low..." BASE_COLOR);
}

const char	*Form::AlreadySigned::what() const throw () {
	return (RED "Form already signed..." BASE_COLOR);
}

std::ostream	&operator << (std::ostream &os, const Form &Form) {
	if (Form.isSigned())
		os << CYAN "Signed Form: " MAGENTA << Form.getName() << CYAN " can be signed by Bureaucrat worth Grade " MAGENTA << Form.getSignGrade() << CYAN " & execute by Bureaucrat worth Grade" MAGENTA << Form.getExeGrade() << BASE_COLOR;
	else
		os << CYAN "Unsigned Form: " MAGENTA << Form.getName() << CYAN " can be signed by Bureaucrat worth Grade " MAGENTA << Form.getSignGrade() << CYAN " & execute by Bureaucrat worth Grade" MAGENTA << Form.getExeGrade() << BASE_COLOR;
	return (os);
}
