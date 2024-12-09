/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:00:48 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 22:53:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	this->DiamondTrap::_name = "XZ_97";
	this->setName(this->DiamondTrap::_name + "_clap_name");
	this->_health = DT_HEALTH;
	this->_energy = DT_ENERGY;
	this->_damage = DT_DAMAGE;
	std::cout << GREEN "A new DiamondTrap robot: " << this->DiamondTrap::_name << " join the arena!" BASE_COLOR << std::endl << std::endl;; 
}

DiamondTrap::DiamondTrap( const std::string &name ) {
	this->DiamondTrap::_name = name;
	this->setName(name + "_clap_name");
	this->_health = DT_HEALTH;
	this->_energy = DT_ENERGY;
	this->_damage = DT_DAMAGE;
	std::cout << GREEN "A new DiamondTrap robot: " << this->DiamondTrap::_name << " join the arena!" BASE_COLOR << std::endl << std::endl;;
}

DiamondTrap::DiamondTrap( const DiamondTrap &src ) {
	*this = src;
	std::cout << GREEN "DiamondTrap Copy constructor called" BASE_COLOR << std::endl << std::endl;;
}

DiamondTrap &DiamondTrap::operator = ( const DiamondTrap &rhs ) {
	std::cout << GREEN "DiamondTrap Copy assignment operator called" BASE_COLOR << std::endl << std::endl;;
	if (this == &rhs)
		return (*this);
	this->DiamondTrap::_name = rhs.DiamondTrap::_name;
	this->setName(this->DiamondTrap::_name + "_clap_name");
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << YELLOW << "DiamondTrap: " << this->DiamondTrap::_name << " is out of the arena..." BASE_COLOR << std::endl;
}

void	DiamondTrap::attack( const std::string &target ) {
	this->ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << BLUE "Hello my name is: " << MAGENTA << this->DiamondTrap::_name << BLUE " and my ClapTrap name is: " << MAGENTA << this->getName() << BASE_COLOR << std::endl << std::endl;
}
