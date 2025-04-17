/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:45 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 13:25:09 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
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

typedef struct	s_data {
	int	data;
}		t_data;

class Serializer {
public:
	static uintptr_t	serialize( t_data* ptr );
	static t_data*	deserialize( uintptr_t raw );
private:
	Serializer( void );
	Serializer( cref(Serializer) rhs );
	Serializer &operator = ( cref(Serializer) rhs );
	~Serializer( void );
};

#endif //SERIALIZER_HPP
