/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 08:45:41 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 14:02:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie() {
    _name   = "";
}

// Destructor
Zombie::~Zombie() {
    std::cout << "Rest In Peace " << this->_name << ". You just died once again..." << std::endl;
}

// Getters
std::string    Zombie::getName() {
    return (_name);
}
// Setters
void    Zombie::setName(std::string new_name) {
    this->_name = new_name;
}

void    Zombie::annonce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}