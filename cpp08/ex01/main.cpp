/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/03 15:26:06 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {
	try {
		Span list = Span(5);
		
		list.addNumber(6);
		list.addNumber(3);
		list.addNumber(17);
		list.addNumber(9);
		list.addNumber(11);

		PRINT CYAN "Shortest Span: "AND MAGENTA AND list.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND list.longestSpan() CENDL;
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}
	try {
		Span list(4);

		list.addNumber(-10);
		list.addNumber(0);
		list.addNumber(5);
		list.addNumber(10);

		PRINT CYAN "Shortest Span: "AND MAGENTA AND list.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND list.longestSpan() CENDL;

		list.addNumber(3);
		list.addNumber(1);
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}
	try {
		Span list(10);

		list.addNumber(6);

		PRINT CYAN "Shortest Span: "AND MAGENTA AND list.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND list.longestSpan() CENDL;
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}

	return 0;
}
