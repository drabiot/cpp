/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:44:30 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/19 20:27:58 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char **argv ) {
	if (argc != 2) {
		ERROR RED "Error: Need one input" CENDL;
		return (1);
	}

	str input = argv[1];
	if (input.find_first_not_of("0123456789 +-*/") != str::npos) {
		ERROR RED "Error: Bad character in your input detected" CENDL;
		return (1);
	}

	RPN rpn;
	for (size_t i = 0; i < input.size(); ++i) {
		if (isdigit(input.at(i))) {
			rpn.pushInStack(input.at(i) - 48);
		}
		else if (!iswspace(input.at(i))) {
			if (!rpn.makeOperation(input.at(i)))
				return (1);
		}
	}
	
	if (!rpn.checkStack())
		return (1);
	return (0);
}
