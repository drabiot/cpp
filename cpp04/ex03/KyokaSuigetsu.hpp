//
// Created by mscheman on 11/13/24.
//

#ifndef KYOKA_SUIGETSU_H
# define KYOKA_SUIGETSU_H

# include "AMateria.hpp"

class KyokaSuigetsu : public AMateria {
	public:
		// Canonical Orthodox Form
		KyokaSuigetsu();
		KyokaSuigetsu(const KyokaSuigetsu &src);
		KyokaSuigetsu &operator = (const KyokaSuigetsu &rhs);
		~KyokaSuigetsu();

		// Override Function
		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);

};

#endif //KYOKA_SUIGETSU_H
