/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:38:57 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 00:42:42 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaList.hpp"

MateriaList::MateriaList() {
	this->_lenList = 0;
	this->_list = NULL;
	std::cout << GREEN "MateriaList being created" BASE_COLOR << std::endl;
}

MateriaList::MateriaList( const MateriaList &src ) {
	*this = src;
	std::cout << GREEN "MateriaList Copy constructor called" BASE_COLOR << std::endl;
}

MateriaList &MateriaList::operator = ( const MateriaList &rhs ) {
	std::cout << GREEN "MateriaList Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_lenList = rhs._lenList;
	this->clear();
	this->_list = new AMateria *[this->_lenList];
	for (size_t i = 0; i < rhs._lenList; i++)
		this->_list[i] = rhs._list[i];
	return (*this);
}

MateriaList::~MateriaList() {
	std::cout << YELLOW << "MateriaList being destroyed" BASE_COLOR << std::endl;
}

void	MateriaList::add( AMateria *m ) {
	AMateria **tmp;

	this->_lenList++;
	tmp = new AMateria *[this->_lenList];
	for (size_t i = 0; i < this->_lenList - 1; ++i) {
		tmp[i] = this->_list[i];
	}
	tmp[this->_lenList - 1] = m;
	delete [] this->_list;
	this->_list = tmp;
}

void	MateriaList::clear() {
	for (size_t i = 0; i < this->_lenList; i++) {
		delete this->_list[i];
	}
	delete [] this->_list;
}
