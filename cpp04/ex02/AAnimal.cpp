/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:31 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/07 17:25:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	this->_type = "Typeless";
	std::cout << GREEN "An AAnimal appears" BASE_COLOR << std::endl;
}

AAnimal::AAnimal( const std::string &type ) {
	this->_type = type;
	std::cout << GREEN "An AAnimal appears" BASE_COLOR << std::endl;
}

AAnimal::AAnimal( const AAnimal &src ) {
	*this = src;
	std::cout << GREEN "AAnimal Copy constructor called" BASE_COLOR << std::endl;
}

AAnimal &AAnimal::operator = ( const AAnimal &rhs ) {
	std::cout << GREEN "AAnimal Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

AAnimal::~AAnimal() {
	std::cout << YELLOW << "An AAnimal left" BASE_COLOR << std::endl;
}

std::string	AAnimal::getType() const {
	return (this->_type);
}
