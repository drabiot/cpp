/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:42:35 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 20:28:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN "A Brain is created" BASE_COLOR << std::endl;
}

Brain::Brain( const Brain &src ) {
	*this = src;
	std::cout << GREEN "Brain Copy constructor called" BASE_COLOR << std::endl;
}

Brain &Brain::operator = ( const Brain &rhs ) {
	std::cout << GREEN "Brain Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < 100; ++i)
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << YELLOW << "A Brain exploded" BASE_COLOR << std::endl;
}
