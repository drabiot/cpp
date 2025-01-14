/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:46:23 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/14 21:05:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {
	this->_name = "nameless";
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << GREEN "A nameless character join this world" BASE_COLOR << std::endl;
}

Character::Character( const std::string &name ) {
	this->_name = name;
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << GREEN "A character named " << MAGENTA << this->_name << GREEN " join this world" BASE_COLOR << std::endl;
}

Character::Character( const Character &src ) {
	*this = src;
	std::cout << GREEN "Character Copy constructor called" BASE_COLOR << std::endl;
}

Character &Character::operator = ( const Character &rhs) {
	std::cout << GREEN "Character Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	for (size_t i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = rhs._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

Character::~Character( void ) {
	std::cout << MAGENTA << this->_name << YELLOW << " leaved us..." BASE_COLOR << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (!m)
		std::cout << RED << "No materia to equip..." BASE_COLOR << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			std::cout << MAGENTA << this->_name << BLUE " equiped a " << MAGENTA << m->getType() << BLUE " Materia in his inventory" BASE_COLOR << std::endl;
			return ;
		}
	}
	std::cout << MAGENTA << this->_name << BLUE " couldn't equip a " << MAGENTA << m->getType() << BLUE " Materia in his inventory" BASE_COLOR << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
		std::cout << MAGENTA << this->_name << BLUE " unequip a " << MAGENTA << this->_inventory[idx]->getType() << BLUE " Materia off his inventory" BASE_COLOR << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (this->_inventory[idx] == __nullptr)
		return ;
	this->_inventory[idx]->use(target);
}
