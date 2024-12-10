/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:33 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:24:36 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal( "Dog" ) {
	std::cout << GREEN "A Dog appears" BASE_COLOR << std::endl;
}

Dog::Dog( const Dog &src ) : Animal( "Dog" ) {
	*this = src;
	std::cout << GREEN "Dog Copy constructor called" BASE_COLOR << std::endl;
}

Dog &Dog::operator = ( const Dog &rhs ) {
	std::cout << GREEN "Dog Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

Dog::~Dog() {
	std::cout << YELLOW << "A Dog left" BASE_COLOR << std::endl;
}

void	Dog::makeSound() const {
	std::cout << CYAN "The Dog Barked" BASE_COLOR << std::endl;
}
