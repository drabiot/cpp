/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/05 01:46:52 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main( void ) {
	try {
		Span list = Span(5);
		
		list.addNumber(6);
		list.addNumber(3);
		list.addNumber(17);
		list.addNumber(9);
		list.addNumber(11);

		PRINT CYAN "Shortest Span: " AND MAGENTA AND list.shortestSpan() CENDL;
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

		PRINT CYAN "Shortest Span: " AND MAGENTA AND list.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND list.longestSpan() CENDL;

		list.addNumber(3);
		list.addNumber(1);
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}
	try {
		Span list(10);

		list.addNumber(6);

		PRINT CYAN "Shortest Span: " AND MAGENTA AND list.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND list.longestSpan() CENDL;
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}
	try {
		Span list = Span(5);
		
		list.addNumber(6);
		list.addNumber(3);
		list.addNumber(17);
		list.addNumber(9);
		list.addNumber(11);

		Span listit(10);
		listit.addNumber(list.getBegin(), list.getEnd());

		PRINT CYAN "Shortest Span: " AND MAGENTA AND listit.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND listit.longestSpan() CENDL;
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}
	try {
		 std::srand(std::time(0));
		Span list= Span(1e5);

		for (size_t i = 0; i < 1e5; ++i) {
			list.addNumber(std::rand());
		}

		PRINT CYAN "Shortest Span: " AND MAGENTA AND list.shortestSpan() CENDL;
		PRINT CYAN "Longest Span: " AND MAGENTA AND list.longestSpan() CENDL;
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
	}

	return 0;
}
