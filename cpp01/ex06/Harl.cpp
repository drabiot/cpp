/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:45:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/27 18:54:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static const std::string	_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

// Constructor
Harl::Harl() {
	std::cout << GREEN "Harl is created" BASE_COLOR << std::endl << std::endl;
}

// Destructor
Harl::~Harl() {
	std::cout << std::endl << YELLOW "Harl is destroyed" BASE_COLOR << std::endl;
}

void	Harl::debug() {
	std::cout << GREEN "\tYpoulett :D" BASE_COLOR << std::endl;
}

void	Harl::info() {
	std::cout << CYAN "\tYpoulett n'est pas la" BASE_COLOR << std::endl;
}

void	Harl::warning() {
	std::cout << YELLOW "\tWaza non Ypoulett" BASE_COLOR << std::endl;
}

void	Harl::error() {
	std::cout << RED "\tYPOULETT WTF CE POULET !" BASE_COLOR << std::endl;
}

void	Harl::incorrect() {
	std::cout << MAGENTA "\tROAR ZABIMARU !" BASE_COLOR << std::endl;
}


void	Harl::complain(std::string level) {
	size_t	i;

	for (i = 0; i < 5; i++)
		if (!level.compare(_level[i]))
			break;
	if (i < 4)
		std::cout << "[" << _level[i] << "]" << std::endl;
	else
		std::cout << "[INCORRECT]" << std::endl;
	switch (i)
	{
		case 0:
			debug();
			HARL_FALLTHROUGH;
		case 1:
			info();
			HARL_FALLTHROUGH;
		case 2:
			warning();
			HARL_FALLTHROUGH;
		case 3:
			error();
			break;
		default:
			incorrect();
			break;
	};

}
