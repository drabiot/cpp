/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:37:32 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 21:12:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_name = "XZ_97";
	this->_health = ST_HEALTH;
	this->_energy = ST_ENERGY;
	this->_damage = ST_DAMAGE;
	this->_isGuard = false;
	std::cout << GREEN "A new ScavTrap robot: " << this->_name << " join the arena!" BASE_COLOR << std::endl << std::endl;; 
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name) {
	this->_name = name;
	this->_health = ST_HEALTH;
	this->_energy = ST_ENERGY;
	this->_damage = ST_DAMAGE;
	this->_isGuard = false;
	std::cout << GREEN "A new ScavTrap robot: " << this->_name << " join the arena!" BASE_COLOR << std::endl << std::endl;;
}

ScavTrap::ScavTrap( const ScavTrap &src ) : ClapTrap(src) {
	*this = src;
	std::cout << GREEN "ScavTrap Copy constructor called" BASE_COLOR << std::endl << std::endl;;
}

ScavTrap &ScavTrap::operator = ( const ScavTrap &rhs ) {
	std::cout << GREEN "ScavTrap Copy assignment operator called" BASE_COLOR << std::endl << std::endl;;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	this->_isGuard = rhs._isGuard;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << YELLOW << "ScavTrap: " << this->_name << " is out of the arena..." BASE_COLOR << std::endl;
}

void	ScavTrap::attack( const std::string &target ) {
	if (this->_energy <= 0 || this->_health <= 0) {
		std::cout << RED "The ScavTrap robot remains stuck" BASE_COLOR << std::endl << std::endl;
		return ;
	}

	std::cout << CYAN "ScavTrap: " << MAGENTA << this->_name << CYAN " attacks ";
	if (target.empty())
		std::cout << MAGENTA "nobody";
	else
		std::cout << MAGENTA << target;
	std::cout << CYAN ", causing " << RED << this->_damage << CYAN " points of damage!" BASE_COLOR << std::endl << std::endl;;
	this->_energy--;
}

void	ScavTrap::guardGate() {
	if (this->_energy <= 0 || this->_health <= 0) {
		std::cout << RED "The ScavTrap robot can't guard" BASE_COLOR << std::endl << std::endl;
		return ;
	}
	if (this->_isGuard == false) {
		this->_isGuard = true;
		std::cout << MAGENTA << this->_name << BLUE " is now in Gate keeper mode" BASE_COLOR << std::endl << std::endl;
	}
	else {
		this->_isGuard = false;
		std::cout << MAGENTA << this->_name << BLUE " is no longer in Gate keeper mode" BASE_COLOR << std::endl << std::endl;
	}
}
