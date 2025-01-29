/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:27:53 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
			Bureaucrat Stefan("Stefan", 1);
			Bureaucrat Niko("Niko", 150);
			
			Form	Form1;
			Form	Form2("Poor People's Tax", 1, 1);
			Form	Form3(Form1);
			
			Niko.signForm(Form1);
			Niko.signForm(Form2);
			Stefan.signForm(Form1);
			Stefan.signForm(Form2);
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Bureaucrat Stefan("Stefan", 1);
		try {			
			Form	Form1("Basic Form", 0, 10);
			
			Stefan.signForm(Form1);
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		try {			
			Form	Form1("Basic Form", 200, 10);
			
			Stefan.signForm(Form1);
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
