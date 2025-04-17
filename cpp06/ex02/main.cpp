/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 15:37:12 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base	*test;

	std::srand(std::time(NULL));
	try
	{
		test = generate();
		identify(test);
		identify(*test);
	}
	catch(const std::exception& e)
	{
		ERROR e.what() ENDL;
	}
	delete test;
}
