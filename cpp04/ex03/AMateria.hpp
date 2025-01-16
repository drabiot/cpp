/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:16:14 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 00:38:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "color.hpp"
# include "ICharacter.hpp"
# include "MateriaSource.hpp"
# include "MateriaList.hpp"

class MateriaList;

class AMateria
{
public:
	AMateria( void );
	AMateria( const std::string &type );
	AMateria( const AMateria &src );
	AMateria &operator = ( const AMateria &rhs );
	virtual ~AMateria( void );

	std::string const & getType() const; //Returns the materia type

	virtual	AMateria*	clone() const = 0;
	virtual	void 		use( ICharacter& target );

	static void			unleak( void );
protected:
	std::string			_type;
private:
	static MateriaList	_list;
};

#endif //AANIMAL_HPP
