//
// Created by mscheman on 11/13/24.
//

#ifndef GETSUGA_TENSHO_H
# define GETSUGA_TENSHO_H

# include "AMateria.hpp"

class GetsugaTensho : public AMateria {
	public:
		// Canonical Orthodox Form
		GetsugaTensho();
		GetsugaTensho(const GetsugaTensho &src);
		GetsugaTensho &operator = (const GetsugaTensho &rhs);
		~GetsugaTensho();

		// Override Function
		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);

};

#endif //GETSUGA_TENSHO_H
