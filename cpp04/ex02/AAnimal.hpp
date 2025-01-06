/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:44:39 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 21:55:40 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "color.hpp"
# include "Brain.hpp"

class AAnimal {
public:
	AAnimal( void );
	AAnimal( const std::string &type );
	AAnimal( const AAnimal &src );
	AAnimal &operator = ( const AAnimal &rhs );
	virtual ~AAnimal( void );

	virtual void	makeSound( void ) const = 0;
	std::string		getType( void ) const;
protected:
	std::string	_type;
};

#endif //AANIMAL_HPP