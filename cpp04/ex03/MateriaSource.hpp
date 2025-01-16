/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:45:24 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 00:50:31 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

# define AS_SPELLBOOK dynamic_cast<MateriaSource *>

class MateriaSource : public IMateriaSource {
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &src );
	MateriaSource &operator = ( const MateriaSource &rhs );
	~MateriaSource( void );
	
	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
	void print(std::string const & name = "Universal SpellBook");
private:
	AMateria *_inventory[4];
};

#endif //MATERIASOURCE_HPP
