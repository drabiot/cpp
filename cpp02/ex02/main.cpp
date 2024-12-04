/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:01:50 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/04 21:28:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {
	{	// ex00
		Fixed a;
		Fixed b(a);
		Fixed c;

		c = b;

		a.setRawBits(10);
		b.setRawBits(100);
		c.setRawBits(1000);

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << std::endl;
	{	// ex01
		Fixed a;
		const Fixed b = 10;
		const Fixed c = 42.42f;
		const Fixed d( b );

		a = Fixed( 1234.4321f );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;

		std::cout << "a is " << a.toFloat() << " as float" << std::endl;
		std::cout << "b is " << b.toFloat() << " as float" << std::endl;
		std::cout << "c is " << c.toFloat() << " as float" << std::endl;
		std::cout << "d is " << d.toFloat() << " as float" << std::endl;

		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	std::cout << std::endl;
	{	// ex02
		Fixed a = 15;
		Fixed b = 1.5f;
		Fixed c = a;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		{	// Relational Operators
			std::cout << "a > b: " << (a > b) << std::endl;
			std::cout << "a > c: " << (a > c) << std::endl;
			std::cout << "a < b: " << (a < b) << std::endl;
			std::cout << "a < c: " << (a < c) << std::endl;
			std::cout << "a >= b: " << (a >= b) << std::endl;
			std::cout << "a >= c: " << (a >= c) << std::endl;
			std::cout << "a <= b: " << (a <= b) << std::endl;
			std::cout << "a <= c: " << (a <= c) << std::endl;
			std::cout << "a == b: " << (a == b) << std::endl;
			std::cout << "a == c: " << (a == c) << std::endl;
			std::cout << "a != b: " << (a != b) << std::endl;
			std::cout << "a != c: " << (a != c) << std::endl;
		}
		std::cout << std::endl;
		{	// Arithmetic Operators
		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
		}
		std::cout << std::endl;
		{	// Incremental / Decremental Operators
			std::cout << "a; a++; a > " << a << " " << a++ << " " << a << std::endl;
			std::cout << "a; ++a; a > " << a << " " << ++a << " " << a << std::endl;
			std::cout << "a; a--; a > " << a << " " << a-- << " " << a << std::endl;
			std::cout << "a; --a; a > " << a << " " << --a << " " << a << std::endl;
		}
		std::cout << std::endl;
		{	// Static Methods
			std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
			std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
		}
	}
}