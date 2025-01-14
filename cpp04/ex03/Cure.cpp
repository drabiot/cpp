/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/14 21:04:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) {
	this->_type = "cure";
	std::cout << GREEN "A Cure Materia being created" BASE_COLOR << std::endl;
}

Cure::Cure( const Cure &src ) {
	*this = src;
	std::cout << GREEN "Cure Materia Copy constructor called" BASE_COLOR << std::endl;
}

Cure &Cure::operator = ( const Cure &rhs ) {
	std::cout << GREEN "Cure Materia Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

Cure::~Cure( void ) {
	std::cout << YELLOW << "A Cure Materia being destroyed" BASE_COLOR << std::endl;
}


AMateria*	Cure::clone() const {
	AMateria *cureClone = new Cure();
	return (cureClone);
}

void	Cure::use( ICharacter& target ) {
	std::cout << CYAN "⛑️  Heals " << MAGENTA << target.getName() << CYAN "'s wonds ❤️‍🩹" << BASE_COLOR << std::endl;
}