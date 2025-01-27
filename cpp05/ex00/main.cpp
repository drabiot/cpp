/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/27 23:29:45 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		try {
			Bureaucrat Random;
			Bureaucrat Stefan("Stefan", 1);
			Stefan.promoteBureaucrat();
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat Stefan("Stefan", 1);
			Stefan.demoteBureaucrat();
			Stefan.demoteBureaucrat();
			Stefan.demoteBureaucrat();
			Stefan.demoteBureaucrat();
			Stefan.demoteBureaucrat();
			Stefan.demoteBureaucrat();
			std::cout << Stefan << std::endl;
			Stefan.promoteBureaucrat();
			Stefan.promoteBureaucrat();
			Stefan.promoteBureaucrat();
			std::cout << Stefan << std::endl;
			for (size_t i = 0; i < 160; i++) {
				Stefan.demoteBureaucrat();
			}
			// Leave try catch (we don't execute this line of code)
			std::cout << Stefan << std::endl;
			Stefan.promoteBureaucrat();
			Stefan.promoteBureaucrat();
			Stefan.promoteBureaucrat();
			std::cout << Stefan << std::endl;
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat Stefan("Stefan", -10);
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat Stefan("Stefan", 151);
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
