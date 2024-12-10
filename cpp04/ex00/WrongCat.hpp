/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:52:16 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:32:17 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
public:
	WrongCat( void );
	WrongCat( const WrongCat &src );
	WrongCat &operator = ( const WrongCat &rhs );
	~WrongCat( void );

	void	makeSound( void ) const;
};

#endif //WRONGCAT_HPP
