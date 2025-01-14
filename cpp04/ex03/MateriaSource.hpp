/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 20:45:24 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/14 19:07:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource( void );
	MateriaSource( const MateriaSource &src );
	MateriaSource &operator = ( const MateriaSource &rhs );
	~MateriaSource( void );
	
	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
private:
	AMateria *_inventory[4];
};

#endif //MATERIASOURCE_HPP
