/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:15:40 by tchartie          #+#    #+#             */
/*   Updated: 2025/05/01 07:23:10 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base	*generate(void) {
	int	random = std::rand() % 3;

	switch (random)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base* p) {
	if (!p)
	throw (std::out_of_range("Base point to NULL"));
	if (dynamic_cast<A*>(p))
		PRINT CYAN "Type: " MAGENTA "A" CENDL;
	else if (dynamic_cast<B*>(p))
		PRINT CYAN "Type: " MAGENTA "B" CENDL;
	else if (dynamic_cast<C*>(p))
		PRINT CYAN "Type: " MAGENTA "C" CENDL;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		PRINT CYAN "Type: " MAGENTA "A" CENDL;
		return;
	}
	catch (std::exception const &) {}

	try {
		(void)dynamic_cast<B&>(p);
		PRINT CYAN "Type: " MAGENTA "B" CENDL;
		return;
	}
	catch (std::exception const &) {}

	try {
		(void)dynamic_cast<C&>(p);
		PRINT CYAN "Type: " MAGENTA "C" CENDL;
		return;
	}
	catch (std::exception const &) {}

	throw std::out_of_range("Base reference isn't from one of the known classes.");
}
