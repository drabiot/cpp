/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:55 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:23:49 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal( "Cat" ) {
	std::cout << GREEN "A Cat appears" BASE_COLOR << std::endl;
}

Cat::Cat( const Cat &src ) : Animal( "Cat" ) {
	*this = src;
	std::cout << GREEN "Cat Copy constructor called" BASE_COLOR << std::endl;
}

Cat &Cat::operator = ( const Cat &rhs ) {
	std::cout << GREEN "Cat Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

Cat::~Cat() {
	std::cout << YELLOW << "A Cat left" BASE_COLOR << std::endl;
}

void	Cat::makeSound() const {
	std::cout << CYAN "The Cat meowed" BASE_COLOR << std::endl;
}
