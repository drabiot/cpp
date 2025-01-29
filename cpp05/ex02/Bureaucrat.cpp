/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:02:44 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:56:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Nameless") {
	this->_grade = 150;
	std::cout << GREEN "A" MAGENTA " Nameless" GREEN " Bureaucrat join us with the grade of " MAGENTA "150" GREEN "!" BASE_COLOR<< std::endl;
}

Bureaucrat::Bureaucrat( const std::string &name, const int &grade ) : _name(name) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHightException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
	std::cout << GREEN "The Bureaucrat named " MAGENTA << getName() << GREEN " join us with the grade of " MAGENTA << getGrade() << GREEN "!" BASE_COLOR << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) {
	*this = src;
	std::cout << GREEN "Bureaucrat Copy constructor called" BASE_COLOR << std::endl;
}

Bureaucrat &Bureaucrat::operator = ( const Bureaucrat &rhs) {
	std::cout << GREEN "Bureaucrat Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << YELLOW "The Bureaucrat named " MAGENTA << getName() << YELLOW " with the grade of " MAGENTA << getGrade() << YELLOW " left us" BASE_COLOR << std::endl;
}

const std::string	&Bureaucrat::getName( void ) const {
	return (this->_name);
}

const size_t 		&Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

void	Bureaucrat::promoteBureaucrat( void ) {
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHightException());
	this->_grade -= 1;
}

void	Bureaucrat::demoteBureaucrat( void ) {
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade += 1;
}

void	Bureaucrat::signForm(AForm &toSign) {
	try {
		toSign.beSigned(*this);
		std::cout << MAGENTA << this->getName() << BLUE " signed " << MAGENTA << toSign.getName() << BASE_COLOR << std::endl;
	}
	catch(const std::exception & e) {
		std::cerr << MAGENTA << this->getName() << RED " couldn't sign " << MAGENTA << toSign.getName() << RED " because " << MAGENTA << e.what() << BASE_COLOR <<std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << MAGENTA << this->getName() << BLUE " execute " << MAGENTA << form.getName() << BASE_COLOR << std::endl;
	}
	catch(const std::exception & e) {
		std::cerr << MAGENTA << this->getName() << RED " couldn't execute " << MAGENTA << form.getName() << RED " because " << MAGENTA << e.what() << BASE_COLOR <<std::endl;
	}
}

const char	*Bureaucrat::GradeTooHightException::what() const throw () {
	return (RED "Grade too hight..." BASE_COLOR);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw () {
	return (RED "Grade too low..." BASE_COLOR);
}

std::ostream	&operator << (std::ostream &os, const Bureaucrat &Bureaucrat) {
	os << MAGENTA << Bureaucrat.getName() << CYAN ", bureaucrat grade " << MAGENTA << Bureaucrat.getGrade() << BASE_COLOR;
	return (os);
}
