/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:20:42 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/17 13:25:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {
	PRINT GREEN "Create Serializer" CENDL;
}

Serializer::Serializer( cref(Serializer) src ) {
	(void)src;
	PRINT GREEN "Serializer Copy constructor called" CENDL;
}

Serializer &Serializer::operator = ( cref(Serializer) rhs ) {
	(void)rhs;
	PRINT GREEN "Serializer Copy assignment operator called" CENDL;
	return (*this);
}

Serializer::~Serializer( void ) {
	PRINT YELLOW "Destroy Serializer" CENDL;
}

uintptr_t	Serializer::serialize( t_data* ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data*	Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<t_data *>(raw));
}
