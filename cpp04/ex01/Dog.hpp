/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:38 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 20:10:07 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {
public:
	Dog( void );
	Dog( const Dog &src );
	Dog &operator = ( const Dog &rhs );
	~Dog( void );

	void	makeSound( void ) const;
private:
	Brain	*_brain;
};

#endif //DOG_HPP
