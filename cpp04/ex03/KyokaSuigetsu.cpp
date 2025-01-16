//
// Created by mscheman on 11/13/24.
//

#include "KyokaSuigetsu.hpp"

KyokaSuigetsu::KyokaSuigetsu() : AMateria("kyoka suigetsu") {}

KyokaSuigetsu::KyokaSuigetsu(const KyokaSuigetsu &src) : AMateria("kyoka suigetsu") {
	*this = src;
}

KyokaSuigetsu &KyokaSuigetsu::operator=(const KyokaSuigetsu &rhs) {
	if (this == &rhs)
		return *this;
	this->_type = "kyoka suigetsu";
	return *this;
}

KyokaSuigetsu::~KyokaSuigetsu() {}

// Override Function
AMateria *KyokaSuigetsu::clone() const {
	return new KyokaSuigetsu(*this);
}

void KyokaSuigetsu::use(ICharacter &target) {
	std::cout << CYAN "* revealed to " MAGENTA << target.getName();
	std::cout << CYAN " the reality *" BASE_COLOR << std::endl;;
}
