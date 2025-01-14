/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:46:19 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/14 21:05:48 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <vector>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {
public:
	Character( void );
	Character( const std::string &name );
	Character( const Character &src );
	Character &operator = ( const Character &rhs);
	~Character( void );

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria 	*_inventory[4];
};

#endif //CHARACTER_HPP
