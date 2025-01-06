/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:51:38 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 21:53:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"

class	Dog : public AAnimal {
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
