/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:45:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/28 19:18:49 by tchartie         ###   ########.fr       */
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
	std::cout << GREEN "[DEBUG]" << std::endl << "\tI love Yoruichi :D" << std::endl << "\tThis is the best Bleach character" BASE_COLOR << std::endl;
}

void	Harl::info() {
	std::cout << CYAN "[INFO]" << std::endl << "\tYoruichi is the best girl cuz she have a strong aura & she's so BADASS!" BASE_COLOR << std::endl;
}

void	Harl::warning() {
	std::cout << YELLOW "[WARNING]" << std::endl << "\tHow could you tell me that Yoruichi is not the best Bleach character!" << std::endl << "\tI gonna getsuga tenshou you!" BASE_COLOR << std::endl;
}

void	Harl::error() {
	std::cout << RED "[ERROR]" << std::endl << "\tI gonna tell Aizen that you don't like Yoruichi! HE WILL USE HIS HOUGYOKU ON YOU !" BASE_COLOR << std::endl;
}

void	Harl::incorrect() {
	std::cout << MAGENTA "[INCORRECT]" << std::endl << "\tROAR ZABIMARU !" BASE_COLOR << std::endl;
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
