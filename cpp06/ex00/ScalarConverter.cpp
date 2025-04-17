/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:42 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 05:50:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ScalarConverter.hpp"

static void	printPseudoLiterals( cref(str) input );
static bool isLiteral(cref(str) input);

ScalarConverter::ScalarConverter( void ) {
	PRINT GREEN "Create Scalar Converter" CENDL;
}

ScalarConverter::ScalarConverter( cref(ScalarConverter) src ) {
	(void)src;
	PRINT GREEN "Scalar Converter Copy constructor called" CENDL;
}

ScalarConverter &ScalarConverter::operator = ( cref(ScalarConverter) rhs ) {
	(void)rhs;
	PRINT GREEN "Scalar Converter Copy assignment operator called" CENDL;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ) {
	PRINT YELLOW "Destroy Scalar Converter" CENDL;
}

void	ScalarConverter::convert( cref(str) input ) {
	//Check for pseudoLiterals
	
	t_type literalType = ScalarConverter::identify(input);
	if (literalType == E_TYPE_END) {
		ERROR RED "Wrong input: write char, int, float or doubles" CENDL;
		return ;
	}

}

static t_type	identify(cref(str) input) {
	if (std::isalpha(chaine[0]) && chaine.size() == 1)
		return (CHAR);
	if (!isLiteral(input))
		return (E_TYPE_END);
	if (input.find('f') != str::npos)
		return (FLOAT);
	if (input.find('.') != str::npos)
		return (DOUBLE);
	return (INT);
}

void	*startSerialize(cref(str) input, t_type type) {

}

void	print(void *input , t_type type) {

}

static void	printPseudoLiterals(cref(str) input) {
	(void) input;
}

static bool isLiteral(cref(str) input) {
	if (input.empty())
		return (false);

	str::const_iterator it = input.begin();

	if (*it == '+' || *it == '-')
		++it;

	bool	hasDigit = false;
	bool	hasDot = false;

	for (; it != input.end(); ++it) {
		char	c = *it;
		if (std::isdigit(c)) {
			hasDigit = true;
			continue;
		}
		if (c == '.') {
			if (hasDot)
				return (false);
			hasDot = true;
			continue;
		}
		if (c == 'f' || c == 'F') {
			return (it + 1 == input.end() && hasDigit);
		}
		return (false);
	}
	return (hasDigit);
}
