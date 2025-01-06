/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:55 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:36:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal( "WrongCat" ) {
	std::cout << GREEN "A Wrong Cat appears" BASE_COLOR << std::endl;
}

WrongCat::WrongCat( const WrongCat &src ) : WrongAnimal( "WrongCat" ) {
	*this = src;
	std::cout << GREEN "WrongCat Copy constructor called" BASE_COLOR << std::endl;
}

WrongCat &WrongCat::operator = ( const WrongCat &rhs ) {
	std::cout << GREEN "WrongCat Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_type = rhs._type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << YELLOW << "A Wrong Cat left" BASE_COLOR << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << CYAN "The Wrong Cat meowed" BASE_COLOR << std::endl;
}
