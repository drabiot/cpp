/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:15:40 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 15:42:00 by tchartie         ###   ########.fr       */
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
	try
	{
		A a = dynamic_cast<A&>(p);
		PRINT CYAN "Type: " MAGENTA "A" CENDL;
	}
	catch(const std::exception& e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			PRINT CYAN "Type: " MAGENTA "B" CENDL;
		}
		catch(const std::exception& e)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				PRINT CYAN "Type: " MAGENTA "C" CENDL;
			}
			catch (const std::exception &e)
			{
				throw (std::out_of_range("Base reference isn't from one of the class."));
			}
		}
	}
}
