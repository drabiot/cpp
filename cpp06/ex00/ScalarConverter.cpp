/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:42 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/30 21:56:14 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	printablePseudoLiterals( cref(str) input );
static bool isLiteral(cref(str) input);

static void	charPrint(char c, bool isDisplay);
static void	intPrint(int i, bool isDisplay);
static void	floatPrint(float f, bool isDisplay);
static void	doublePrint(double d);

static bool	isCharPrintable(bool isInt, int value);
static bool	isFloatInt(float f);
static bool	isDoubleInt(double d);

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

void	ScalarConverter::convert( str input ) {
	if (printablePseudoLiterals(input))
		return;
	t_type literalType = ScalarConverter::identify(input);
	if (literalType == E_TYPE_END) {
		ERROR RED "Wrong input: write char, int, float or doubles" CENDL;
		return;
	}
	void	*data = ScalarConverter::startSerialize(input, literalType);
	if (!data) {
		ERROR RED "Wrong input: an error occured with your input" CENDL;
		return;
	}
	ScalarConverter::print(data, literalType);
	delete static_cast<int *>(data);
}

t_type	ScalarConverter::identify(cref(str) input) {
	if (std::isprint(input[0]) && input.size() == 1)
		return (CHAR);
	if (!isLiteral(input))
		return (E_TYPE_END);
	if (input.find('f') != str::npos)
		return (FLOAT);
	if (input.find('.') != str::npos)
		return (DOUBLE);
	return (INT);
}

void	*ScalarConverter::startSerialize(cref(str) input, t_type type) {
	void	*data;
	long	intData;
	double	floatData;

	switch(type) {
		case CHAR:
			data = new char;
			static_cast<char *>(data)[0] = input[0];
			break;
		case INT:
			intData = std::strtol(input.c_str(), NULL, 10);
			if (intData > INT_MAX || intData < INT_MIN || errno == ERANGE)
				return (NULL);
			data = new int;
			static_cast<int *>(data)[0] = intData;
			break;
		case FLOAT:
			floatData = std::strtod(input.c_str(), NULL);
			if (floatData > FLT_MAX || floatData < -FLT_MAX || errno == ERANGE)
				return (NULL);
			data = new float;
			static_cast<float *>(data)[0] = floatData;
			break;
		case DOUBLE:
			floatData = std::strtod(input.c_str(), NULL);
			if (errno == ERANGE)
				return (NULL);
			data = new double;
			static_cast<double *>(data)[0] = floatData;
			break;
		case E_TYPE_END:
			return (NULL);
			break;
	}
	return data;

}

void	ScalarConverter::print(void *serialize , t_type type) {
	char	charSer;
	int		intSer;
	float	floatSer;
	double	doubleSer;

	switch (type) {
		case CHAR:
			charSer = static_cast<char *>(serialize)[0];
			charPrint(charSer, true);
			intPrint(static_cast<int>(charSer), true);
			floatPrint(static_cast<float>(charSer), true);
			doublePrint(static_cast<double>(charSer));
			break;
		case INT:
			intSer = static_cast<int *>(serialize)[0];
			charPrint(static_cast<char>(intSer), isCharPrintable(true, intSer));
			intPrint(intSer, true);
			floatPrint(static_cast<float>(intSer), true);
			doublePrint(static_cast<double>(intSer));
			break;
		case FLOAT:
			floatSer = static_cast<float *>(serialize)[0];
			charPrint(static_cast<char>(floatSer), isCharPrintable(isFloatInt(floatSer), floatSer));
			intPrint(static_cast<int>(floatSer), (isFloatInt(floatSer) && floatSer <= (float)INT_MAX && floatSer >= INT_MIN));
			floatPrint(floatSer, true);
			doublePrint(static_cast<double>(floatSer));
			break;
		case DOUBLE:
			doubleSer = static_cast<double *>(serialize)[0];
			charPrint(static_cast<char>(doubleSer), isCharPrintable(isFloatInt(doubleSer), doubleSer));
			intPrint(static_cast<int>(doubleSer), (isFloatInt(doubleSer) && doubleSer <= INT_MAX && doubleSer >= INT_MIN));
			floatPrint(static_cast<float>(doubleSer), (doubleSer <= FLT_MAX && doubleSer >= -FLT_MAX));
			doublePrint(doubleSer);
			break;
		case E_TYPE_END:
			return;
			break;
	}
}

static bool	printablePseudoLiterals(cref(str) input) {
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		PRINT BLUE "char:" AND TAB AND MAGENTA AND "impossible" CENDL;
		PRINT BLUE "int:" AND TAB AND MAGENTA AND "impossible" CENDL;
		if (input == "-inff") {
			floatPrint(-__builtin_inff(), true);
			doublePrint(-__builtin_inf());
		}
		else if (input == "+inff") {
			floatPrint(__builtin_inff(), true);
			doublePrint(__builtin_inf());
		}
		else {
			floatPrint(__builtin_nanf("0x7fc00000"), true);
			doublePrint(__builtin_nan("0x7fc00000"));
		}
		return (true);
	}
	if (input == "-inf" || input == "+inf" || input == "nan") {
		PRINT BLUE "char:" AND TAB AND MAGENTA AND "impossible" CENDL;
		PRINT BLUE "int:" AND TAB AND MAGENTA AND "impossible" CENDL;
		//PRINT BLUE "float:" AND TAB AND MAGENTA AND "impossible" CENDL;
		if (input == "-inf") {
			floatPrint(-__builtin_inff(), true);
			doublePrint(-__builtin_inf());
		}
		else if (input == "+inf") {
			floatPrint(__builtin_inff(), true);
			doublePrint(__builtin_inf());
		}
		else {
			floatPrint(__builtin_nanf("0x7fc00000"), true);
			doublePrint(__builtin_nan("0x7fc00000"));
		}
		return (true);
	}
	return (false);
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

static void	charPrint(char c, bool isDisplay) {
	PRINT BLUE "char:" AND TAB BASE_COLOR;
	if (!isDisplay)
		PRINT MAGENTA "Non displayable" CENDL;
	else
		PRINT CYAN AND c CENDL;
}

static void	intPrint(int i, bool isDisplay) {
	PRINT BLUE "int:" AND TAB BASE_COLOR;
	if (!isDisplay)
		PRINT MAGENTA "Non displayable" CENDL;
	else
		PRINT CYAN AND i CENDL;
}

static void	floatPrint(float f, bool isDisplay) {
	PRINT BLUE "float:" AND TAB BASE_COLOR;
	if (!isDisplay)
		PRINT MAGENTA "Non displayable" CENDL;
	else {
		if (isFloatInt(f) && f < 1e6)
			PRINT CYAN AND f AND ".0";
		else
			PRINT CYAN AND f;
		PRINT "f" CENDL;
	}
}

static void	doublePrint(double d) {
	PRINT BLUE "double:" AND TAB BASE_COLOR;
	if (isDoubleInt(d) && d < 1e6)
		PRINT CYAN AND d AND ".0";
	else
		PRINT CYAN AND d CENDL;
}

static bool	isCharPrintable(bool isInt, int value) {
	if (!isInt)
		return (false);
	if (value > CHAR_MAX || value < CHAR_MIN)
		return (false);
	if (!isprint(value))
		return (false);
	return (true);
}

static bool	isFloatInt(float f) {
	return (f == static_cast<int>(f) &&
			f >= static_cast<float>(INT_MIN) &&
			f <= static_cast<float>(INT_MAX));
}

static bool	isDoubleInt(double d) {
	return (d == static_cast<int>(d) &&
			d >= static_cast<double>(INT_MIN) &&
			d <= static_cast<double>(INT_MAX));
}
