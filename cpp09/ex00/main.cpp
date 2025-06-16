/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/16 17:54:41 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char **argv ) {
	if (argc < 2) {
		ERROR RED "Need an input" CENDL;
		return (2);
	}
	if (argc > 2) {
		ERROR RED "Too many input" CENDL;
		return (2);
	}

	try {
		BitcoinExchange btc;

		btc.run(argv[1]);
	} catch (const std::exception& e) {
		ERROR RED AND e.what() CENDL;
		return (1);
	}
	return (0);
}
