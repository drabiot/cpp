/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/02/01 16:40:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main()
{
	{
		try {
			Bureaucrat	Stefan("Stefan", 1);
			Intern		Mbatty;
			AForm		*form;

			form = Mbatty.makeForm("Presidential Pardon", "Chigg");
			Stefan.signForm(*form);
			Stefan.executeForm(*form);
			delete form;
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try {
			Intern		Mbatty;
			AForm		*form;

			form = Mbatty.makeForm("PrEsIDEntial PaRDon", "Chigg");
			delete form;
			form = Mbatty.makeForm("ShrUBBEry CReaTiOn", "Deku");
			delete form;
			form = Mbatty.makeForm("RoBotoMy ReqUesT", "Chigg");
			delete form;
			form = Mbatty.makeForm("Omega Form of Doom", "Chigg");
		}
		catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}
