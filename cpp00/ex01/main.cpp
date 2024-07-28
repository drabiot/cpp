/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:13:06 by tchartie          #+#    #+#             */
/*   Updated: 2024/07/27 23:13:06 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "phonebook.hpp"

const static std::string	phoneBookCommands[]{"ADD", "SEARCH", "EXIT"};

int	check_cmd(std::string command, PhoneBook *phonebook)
{
	for (size_t i = 0; i <= 3; i++)
		if (!command.compare(phoneBookCommands[i]))
			break;
	switch (i) {
		case 0:
			(*phonebook).addNewContact();
		case 1:
			(*phonebook).searchContact();
		case 2: {
			std::cout << "See you next time!" << std::endl;
			return (1);
		}
		case 3: {
			std::cout << "Invalid command: You need to choose between ADD, SEARCH & EXIT" << std::endl;
			break;
		}
	}
	return (0);
}

int 	main(int argc, char **argv)
{
	PhoneBook   phonebook;
	std::string command;

	(void)argv;
	if (argc != 1)
		return (1);
	//print tutorial//
	while (std::cin.eof() != 1)
	{
		std::cout << "> ";
		std::getline(std::cin, command);
		if (check_cmd(command, &phonebook) == 1)
			break;
	}
	return (0);
}