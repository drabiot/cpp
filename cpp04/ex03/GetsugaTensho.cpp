//
// Created by mscheman on 11/13/24.
//

#include "GetsugaTensho.hpp"

GetsugaTensho::GetsugaTensho() : AMateria("getsuga tensho") {}

GetsugaTensho::GetsugaTensho(const GetsugaTensho &src) : AMateria("getsuga tensho") {
	*this = src;
}

GetsugaTensho &GetsugaTensho::operator=(const GetsugaTensho &rhs) {
	if (this == &rhs)
		return *this;
	this->_type = "getsuga tensho";
	return *this;
}

GetsugaTensho::~GetsugaTensho() {}

// Override Function
AMateria *GetsugaTensho::clone() const {
	return new GetsugaTensho(*this);
}

void GetsugaTensho::use(ICharacter &target) {
	std::cout << CYAN "* shot an spiritual energy slash to " MAGENTA << target.getName();
	std::cout << CYAN " *" BASE_COLOR << std::endl;;
}
