/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:33:59 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 16:48:15 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string		string = "HI THIS IS BRAIN";
    std::string		*stringPTR = &string;
	std::string		&stringREF = string;


    std::cout << "Memory address of the string variable:  " << &string << std::endl;
	std::cout << "Memory address held by stringPTR:       " << &stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:       " << &stringREF << std::endl << std::endl;

	std::cout << "Value of the string variable:           " << string << std::endl;
	std::cout << "Value pointed to by stringPTR:          " << stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:          " << stringREF << std::endl;
}