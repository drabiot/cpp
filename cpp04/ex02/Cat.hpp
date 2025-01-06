/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:52:16 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/06 21:52:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class	Cat : public AAnimal {
public:
	Cat( void );
	Cat( const Cat &src );
	Cat &operator = ( const Cat &rhs );
	~Cat( void );

	void	makeSound( void ) const;
private:
	Brain	*_brain;
};

#endif //CAT_HPP
