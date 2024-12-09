/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:40:09 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/09 21:02:39 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_name = "XZ_97";
	this->_health = FT_HEALTH;
	this->_energy = FT_ENERGY;
	this->_damage = FT_DAMAGE;
	std::cout << GREEN "A new FragTrap robot: " << this->_name << " join the arena!" BASE_COLOR << std::endl << std::endl;; 
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name) {
	this->_name = name;
	this->_health = FT_HEALTH;
	this->_energy = FT_ENERGY;
	this->_damage = FT_DAMAGE;
	std::cout << GREEN "A new FragTrap robot: " << this->_name << " join the arena!" BASE_COLOR << std::endl << std::endl;;
}

FragTrap::FragTrap( const FragTrap &src ) : ClapTrap(src) {
	*this = src;
	std::cout << GREEN "FragTrap Copy constructor called" BASE_COLOR << std::endl << std::endl;;
}

FragTrap &FragTrap::operator = ( const FragTrap &rhs ) {
	std::cout << GREEN "FragTrap Copy assignment operator called" BASE_COLOR << std::endl << std::endl;;
	if (this == &rhs)
		return (*this);
	this->_name = rhs._name;
	this->_health = rhs._health;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << YELLOW << "FragTrap: " << this->_name << " is out of the arena..." BASE_COLOR << std::endl;
}

void	FragTrap::highFivesGuys() {
	if (this->_energy <= 0 || this->_health <= 0) {
		std::cout << RED "The FragTrap robot can't high five anymore" BASE_COLOR << std::endl << std::endl;
		return ;
	}
	std::cout << BLUE "High Five guys!" BASE_COLOR << std::endl << std::endl;
}
