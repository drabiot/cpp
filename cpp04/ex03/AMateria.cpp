/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:16:02 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/14 18:45:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "Typeless";
	std::cout << GREEN "An AMateria being created" BASE_COLOR << std::endl;
}

AMateria::AMateria( const std::string &type ) {
	this->_type = type;
	std::cout << GREEN "An AMateria being created" BASE_COLOR << std::endl;
}

AMateria::AMateria( const AMateria &src ) {
	*this = src;
	std::cout << GREEN "AMateria Copy constructor called" BASE_COLOR << std::endl;
}

AMateria &AMateria::operator = ( const AMateria &rhs ) {
	std::cout << GREEN "AMateria Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria() {
	std::cout << YELLOW << "An AMateria being destroyed" BASE_COLOR << std::endl;
}

std::string const	& AMateria::getType() const {
	return (this->_type);
}

void	AMateria::use( ICharacter& target ) {
	std::cout << CYAN "💃 Dance in front of " << MAGENTA << target.getName() << CYAN " 💃" << BASE_COLOR << std::endl;
}
