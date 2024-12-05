/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:55 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/05 21:30:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->_name = "XZ_97";
	this->_health = CT_HEALTH;
	this->_energy = CT_ENERGY;
	this->_damage = CT_DAMAGE;
	std::cout << GREEN "A new robot: " << this->_name << " join the arena!" BASE_COLOR << std::endl << std::endl;; 
}

ClapTrap::ClapTrap( const std::string &name ) {
	this->_name = name;
	this->_health = CT_HEALTH;
	this->_energy = CT_ENERGY;
	this->_damage = CT_DAMAGE;
	std::cout << GREEN "A new robot: " << this->_name << " join the arena!" BASE_COLOR << std::endl << std::endl;;
}

ClapTrap::ClapTrap( const ClapTrap &src ) {
	*this = src;
	std::cout << GREEN "Copy constructor called" BASE_COLOR << std::endl << std::endl;;
}

ClapTrap &ClapTrap::operator = ( const ClapTrap &rhs ) {
	std::cout << GREEN "Copy assignment operator called" BASE_COLOR << std::endl << std::endl;;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << YELLOW << this->_name << " is out of the arena..." BASE_COLOR << std::endl;
}

void	ClapTrap::setName( const std::string &name ) {
	std::cout << MAGENTA << this->_name << CYAN " change his name by : " << name << "!" BASE_COLOR << std::endl;
	this->_name = name;
}

void	ClapTrap::setHealth( const int &i ) {
	this->_health = i;
}

void	ClapTrap::setEnergy( const int &i ) {
	this->_energy = i;
}

void	ClapTrap::setDamage( const int &i ) {
	this->_damage = i;
}


const std::string	ClapTrap::getName( void ) {
	return (this->_name);
}

int	ClapTrap::getHealth( void ) {
	return (this->_health);
}

int	ClapTrap::getEnergy( void ) {
	return (this->_energy);
}

int	ClapTrap::getDamage( void ) {
	return (this->_damage);
}

void	ClapTrap::attack( const std::string &target ) {
	if (this->_energy <= 0 || this->_health <= 0) {
		std::cout << RED "The robot remains stuck" BASE_COLOR << std::endl << std::endl;
		return ;
	}

	std::cout << MAGENTA << this->_name << CYAN " attacks ";
	if (target.empty())
		std::cout << MAGENTA "nobody";
	else
		std::cout << MAGENTA << target;
	std::cout << CYAN ", causing " << RED << this->_damage << CYAN " points of damage!" BASE_COLOR << std::endl << std::endl;;
	this->_energy--;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_health <= 0) {
		std::cout << RED "The robot is already in spare parts" BASE_COLOR << std::endl << std::endl;
		return ;
	}

	if (amount == 0) {
		std::cout << MAGENTA << this->_name << CYAN " take no damage!" << std::endl << "He still have " << this->_health << " health point!" << std::endl << std::endl;
		return ;
	}

	std::cout << MAGENTA << this->_name << CYAN " take " << RED << amount << CYAN " points of damage!" BASE_COLOR << std::endl;
	std::cout << CYAN "His " << this->_health << " health point drop to " BASE_COLOR;
	this->_health -= amount;
	if (this->_health < 0)
	{
		this->_health = 0;
		std::cout << CYAN << this->_health << "! " RED "And it's a critical hit!" BASE_COLOR << std::endl << std::endl;;
	}
	else
		std::cout << CYAN << this->_health << "!" BASE_COLOR << std::endl << std::endl;;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energy <= 0 || this->_health <= 0) {
		std::cout << RED "It is impossible to repair it" BASE_COLOR << std::endl << std::endl;
		return ;
	}

	std::cout << MAGENTA << this->_name << CYAN " was repaired worth " << MAGENTA << amount << " health " BASE_COLOR << std::endl;
	std::cout << CYAN "His " << this->_health << " health point increases to " BASE_COLOR;
	this->_health += amount;
	std::cout << CYAN << this->_health << BASE_COLOR << std::endl << std::endl;
	this->_energy--;
}

