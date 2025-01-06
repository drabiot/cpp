/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:39 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:29:38 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include "color.hpp"

class WrongAnimal {
public:
	WrongAnimal( void );
	WrongAnimal( const std::string &type );
	WrongAnimal( const WrongAnimal &src );
	WrongAnimal &operator = ( const WrongAnimal &rhs );
	virtual ~WrongAnimal( void );

	void		makeSound( void ) const;
	std::string	getType( void ) const;
protected:
	std::string	_type;
};

#endif //WRONGANIMAL_HPP