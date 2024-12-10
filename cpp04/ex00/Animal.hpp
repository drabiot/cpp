/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:39 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:25:24 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "color.hpp"

class Animal {
public:
	Animal( void );
	Animal( const std::string &type );
	Animal( const Animal &src );
	Animal &operator = ( const Animal &rhs );
	virtual ~Animal( void );

	virtual void	makeSound( void ) const;
	std::string		getType( void ) const;
protected:
	std::string	_type;
};

#endif //ANIMAL_HPP