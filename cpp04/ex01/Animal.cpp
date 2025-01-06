/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:31 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:26:29 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->_type = "Typeless";
	std::cout << GREEN "An Animal appears" BASE_COLOR << std::endl;
}

Animal::Animal( const std::string &type ) {
	this->_type = type;
	std::cout << GREEN "An Animal appears" BASE_COLOR << std::endl;
}

Animal::Animal( const Animal &src ) {
	*this = src;
	std::cout << GREEN "Animal Copy constructor called" BASE_COLOR << std::endl;
}

Animal &Animal::operator = ( const Animal &rhs ) {
	std::cout << GREEN "Animal Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

Animal::~Animal() {
	std::cout << YELLOW << "An Animal left" BASE_COLOR << std::endl;
}

void	Animal::makeSound() const {
	std::cout << CYAN "Weird animals sounds" BASE_COLOR << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}
