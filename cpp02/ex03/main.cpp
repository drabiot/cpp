/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:01:50 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/04 23:47:10 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void callBsp(const Point &a, const Point &b, const Point &c, const Point &p) {
	std::cout << CYAN "The point p (" << p.getX() << "; " << p.getY() << ") ";
	if (bsp(a, b, c, p))
		std::cout << GREEN "is inside ";
	else
		std::cout << RED "is outside ";
	std::cout << CYAN "the triangle." BASE_COLOR << std::endl;
}

int	main( void ) {
	{
		float	x = 0;
		float	y = 0;

		Point a(x, y);

		x = 2;
		y = 7;
		Point b(x, y);

		x = 4;
		y = 1;
		Point c(x, y);

		x = 3;
		y = 2;
		Point p(x, y);

		callBsp(a, b, c, p);

		x = -3;
		y = -2;
		p = Point(x, y);

		callBsp(a, b, c, p);
	}
	std::cout << std::endl << std::endl;
	{
		float	x = 0;
		float	y = 0;

		Point a;

		x = 6;
		Point b(x, y);
		
		x = 3;
		y = 6;
		Point c(x, y);

		x = 3;
		y = 2;
		Point p(x, y);

		callBsp(a, b, c, p);

		x = 7;
		y = 3;
		p = Point(x, y);

		callBsp(a, b, c, p);
	}
	std::cout << std::endl << std::endl;
	{
		float	x = 0;
		float	y = 0;

		x = -10;
		y = -5;
		Point a(x, y);

		x = 3;
		y = 1;
		Point b(x, y);
		
		x = -12;
		y = 6;
		Point c(x, y);

		x = -6;
		y = 4;
		Point p(x, y);

		callBsp(a, b, c, p);

		x = -5;
		y = 0;
		p = Point(x, y);

		callBsp(a, b, c, p);
	}
}
