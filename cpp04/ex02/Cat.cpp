/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:55 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 21:52:46 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal( "Cat" ) {
	this->_brain = new Brain();
	std::cout << GREEN "A Cat appears" BASE_COLOR << std::endl;
}

Cat::Cat( const Cat &src ) : AAnimal( "Cat" ) {
	*this = src;
	this->_brain = new Brain();
	std::cout << GREEN "Cat Copy constructor called" BASE_COLOR << std::endl;
}

Cat &Cat::operator = ( const Cat &rhs ) {
	std::cout << GREEN "Cat Copy assignment operator called" BASE_COLOR << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;	
		delete this->_brain;
		this->_brain = new Brain();
		*_brain = *rhs._brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->_brain; 
	std::cout << YELLOW << "A Cat left" BASE_COLOR << std::endl;
}

void	Cat::makeSound() const {
	std::cout << CYAN "The Cat meowed" BASE_COLOR << std::endl;
}
