/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:33 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 21:52:59 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal( "Dog" ) {
	this->_brain = new Brain();
	std::cout << GREEN "A Dog appears" BASE_COLOR << std::endl;
}

Dog::Dog( const Dog &src ) : AAnimal( "Dog" ) {
	*this = src;
	this->_brain = new Brain();
	std::cout << GREEN "Dog Copy constructor called" BASE_COLOR << std::endl;
}

Dog &Dog::operator = ( const Dog &rhs ) {
	std::cout << GREEN "Dog Copy assignment operator called" BASE_COLOR << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;	
		delete this->_brain;
		this->_brain = new Brain();
		*_brain = *rhs._brain;
	}
	return (*this);
}

Dog::~Dog() {
	delete this->_brain; 
	std::cout << YELLOW << "A Dog left" BASE_COLOR << std::endl;
}

void	Dog::makeSound() const {
	std::cout << CYAN "The Dog Barked" BASE_COLOR << std::endl;
}
