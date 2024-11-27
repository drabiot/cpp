/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:45:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 02:14:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static const std::string	_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

// Constructor
Harl::Harl() {
	std::cout << GREEN "Harl is created" BASE_COLOR << std::endl;
	_pfnMessage[0] = &Harl::debug;
	_pfnMessage[1] = &Harl::info;
	_pfnMessage[2] = &Harl::warning;
	_pfnMessage[3] = &Harl::error;
	_pfnMessage[4] = &Harl::incorrect;
}

// Destructor
Harl::~Harl() {
	std::cout << YELLOW "Harl is destroyed" BASE_COLOR << std::endl;
}

void	Harl::debug() {
	std::cout << GREEN "[DEBUG] : Ypoulett :D" BASE_COLOR << std::endl;
}

void	Harl::info() {
	std::cout << CYAN "[INFO] : Ypoulett n'est pas la" BASE_COLOR << std::endl;
}

void	Harl::warning() {
	std::cout << YELLOW "[WARNING] : Waza non Ypoulett" BASE_COLOR << std::endl;
}

void	Harl::error() {
	std::cout << RED "[ERROR] : YPOULETT WTF CE POULET !" BASE_COLOR << std::endl;
}

void	Harl::incorrect() {
	std::cout << MAGENTA "[INCORRECT] : ROAR ZABIMARU !" BASE_COLOR << std::endl;
}


void	Harl::complain(std::string level) {
	size_t	i;

	for (i = 0; i < 5; i++)
		if (!level.compare(_level[i]))
			break;
	if (i < 4)
	{
		(this->*_pfnMessage[i])();
		return;
	}
	(this->*_pfnMessage[4])();

}
