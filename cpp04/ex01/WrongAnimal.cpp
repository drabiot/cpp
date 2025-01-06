/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:31 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:33:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->_type = "Typeless";
	std::cout << GREEN "A Wrong Animal appears" BASE_COLOR << std::endl;
}

WrongAnimal::WrongAnimal( const std::string &type ) {
	this->_type = type;
	std::cout << GREEN "A Wrong Animal appears" BASE_COLOR << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src ) {
	*this = src;
	std::cout << GREEN "WrongAnimal Copy constructor called" BASE_COLOR << std::endl;
}

WrongAnimal &WrongAnimal::operator = ( const WrongAnimal &rhs ) {
	std::cout << GREEN "WrongAnimal Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << YELLOW << "A Wrong Animal left" BASE_COLOR << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << CYAN "Weird wrong animals sounds" BASE_COLOR << std::endl;
}

std::string	WrongAnimal::getType() const {
	return (this->_type);
}
