/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:16:17 by tchartie          #+#    #+#             */
/*   Updated: 2025/02/01 16:35:50 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void ) {
	std::cout << GREEN "An Intern joined us" BASE_COLOR << std::endl;
}

Intern::Intern( const Intern &src ) {
	*this = src;
	std::cout << GREEN "Intern Copy constructor called" BASE_COLOR << std::endl;
}

Intern &Intern::operator = ( const Intern &rhs ) {
	std::cout << GREEN "Intern Copy assignment operator called" BASE_COLOR << std::endl;
	static_cast<void>(rhs);
	return (*this);
}

Intern::~Intern( void ) {
	std::cout << YELLOW "An Intern left us" BASE_COLOR << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	int							type;
	std::string					finishName = name;
	const static std::string	FormsName[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (std::string::iterator i = finishName.begin(); i != finishName.end(); i++)
		*i = std::tolower(*i);
	for (type = 0; type < 3; type++) {
		if (finishName == FormsName[type])
			break ;
	}
	switch (type) {
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw (Intern::FormError());
	}
}

const char	*Intern::FormError::what() const throw () {
	return (RED "This Form doesn't exist" BASE_COLOR);
}

