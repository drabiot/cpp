/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:38:57 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 00:33:20 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALIST_HPP
# define MATERIALIST_HPP

# include "AMateria.hpp"

class AMateria;

class MateriaList {
public:
	MateriaList( void );
	MateriaList( const MateriaList &src );
	MateriaList &operator = ( const MateriaList &rhs );
	~MateriaList( void );

	void	add( AMateria *m );
	void	clear( void );
private:
	size_t		_lenList;
	AMateria	**_list;
};

#endif //MATERIALIST_HPP
