/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:35 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/14 18:46:35 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) {
	this->_type = "ice";
	std::cout << GREEN "An Ice Materia being created" BASE_COLOR << std::endl;
}

Ice::Ice( const Ice &src ) {
	*this = src;
	std::cout << GREEN "Ice Materia Copy constructor called" BASE_COLOR << std::endl;
}

Ice &Ice::operator = ( const Ice &rhs ) {
	std::cout << GREEN "Ice Materia Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

Ice::~Ice( void ) {
	std::cout << YELLOW << "An Ice Materia being destroyed" BASE_COLOR << std::endl;
}


AMateria*	Ice::clone() const {
	AMateria *iceClone = new Ice();
	return (iceClone);
}

void	Ice::use( ICharacter& target ) {
	std::cout << CYAN "🪄 Shoot an ice bolt at " << MAGENTA << target.getName() << CYAN " 🧊" << BASE_COLOR << std::endl;
}
