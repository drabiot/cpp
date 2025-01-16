/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:47:20 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 01:05:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << GREEN "A Materia Source being created" BASE_COLOR << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &src ) {
	*this = src;
	std::cout << GREEN "Materia Source Copy constructor called" BASE_COLOR << std::endl;
}

MateriaSource &MateriaSource::operator = ( const MateriaSource &rhs ) {
	std::cout << GREEN "Materia Source Copy assignment constructor called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < 4; i++) {
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource( void ) {
	std::cout << YELLOW << "A Materia Source being destroyed" BASE_COLOR << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia) {
	size_t i;

	for (i = 0; i < 4 && this->_inventory[i]; i++)
		;
	if (!materia)
		std::cout << RED << "No materia to learn..." BASE_COLOR << std::endl;
	else if (i < 4 && this->_inventory[i] == NULL)
		this->_inventory[i] = materia;
	else
		std::cout << RED << "No more space to learn materia..." BASE_COLOR << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (size_t i = 0; i < 4 && this->_inventory[i]; i++) {
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << RED << "No materia with the type " << MAGENTA << type << RED " can be learn here..." BASE_COLOR << std::endl;
	return (NULL);
}

void MateriaSource::print(const std::string &name) {
    bool isEmpty = true;
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            isEmpty = false;
    }
    if (isEmpty) {
        std::cout << MAGENTA << name << YELLOW " is empty" BASE_COLOR << std::endl;
        return ;
    } else {
        std::cout << MAGENTA << name << YELLOW " contains: " BASE_COLOR << std::endl;
    }
    for (int i = 0; i < 4; ++i) {
        std::cout << BASE_COLOR "  Slot " << i + 1 << " > " RED;
        if (_inventory[i])
            std::cout << _inventory[i]->getType();
        else
            std::cout << "None";
        std::cout << std::endl;
    }
}
