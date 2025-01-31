/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/30 10:26:09 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	{
		try {
			Bureaucrat	Stefan("Stefan", 1);
			Bureaucrat	Jean("Jean", 150);
			Bureaucrat	Mathew("Mathew", 25);
			Bureaucrat	George("George", 5);
			
			PresidentialPardonForm	Form1;
			PresidentialPardonForm	Form2("Everybody");

			std::cout << std::endl;
			
			Stefan.signForm(Form1);
			Jean.executeForm(Form1);
			Stefan.executeForm(Form1);

			std::cout << std::endl;

			Mathew.signForm(Form2);
			Mathew.executeForm(Form2);
			Jean.executeForm(Form2);
			George.executeForm(Form2);

			std::cout << std::endl;
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat	Stefan("Stefan", 1);
			Bureaucrat	Jean("Jean", 80);
			Bureaucrat	Mathew("Mathew", 25);
			
			RobotomyRequestForm	Form1;

			std::cout << std::endl;
			
			Stefan.signForm(Form1);

			Mathew.executeForm(Form1);
			Jean.executeForm(Form1);
			Stefan.executeForm(Form1);

			std::cout << std::endl;
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Bureaucrat	Stefan("Stefan", 1);
			Bureaucrat	Jean("Jean", 150);
			Bureaucrat	Mathew("Mathew", 25);
			
			ShrubberyCreationForm	Form1;

			std::cout << std::endl;
			
			Stefan.signForm(Form1);

			Mathew.executeForm(Form1);
			Jean.executeForm(Form1);
			Stefan.executeForm(Form1);

			std::cout << std::endl;
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
