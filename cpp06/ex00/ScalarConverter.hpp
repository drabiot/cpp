/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 06:39:36 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cfloat>
# include <string>
# include "color.hpp"

# define ERROR	std::cerr <<
# define PRINT	std::cout <<
# define AND	<<
# define ENDL	<< std::endl
# define CENDL	<< BASE_COLOR << std::endl
# define TAB	"\t"

typedef std::string str;

# define cref(type) const type &
# define ref(type) type &

typedef enum	e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	E_TYPE_END
}	t_type;

class ScalarConverter {
public:
	static void	convert( str input );
private:
	ScalarConverter( void );
	ScalarConverter( cref(ScalarConverter) rhs );
	ScalarConverter &operator = ( cref(ScalarConverter) rhs );
	~ScalarConverter( void );

	static t_type	identify( cref(str) input );
	static void		*startSerialize( cref(str) input, t_type type );
	static void		print( void *serialize , t_type type );
};

#endif //SCALARCONVERTER_HPP
