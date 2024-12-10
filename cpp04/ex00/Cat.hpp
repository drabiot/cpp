/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:52:16 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:22:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {
public:
	Cat( void );
	Cat( const Cat &src );
	Cat &operator = ( const Cat &rhs );
	~Cat( void );

	void	makeSound( void ) const;
};

#endif //CAT_HPP
