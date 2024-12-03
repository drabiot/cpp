/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:02:07 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/03 22:23:43 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	this->_num = 0;
	std::cout << GREEN "Default constructor called" BASE_COLOR << std::endl;
}

Fixed::Fixed(const int num) {
	this->_num = num * (1 << this->_bit);
	std::cout << GREEN "Int constructor called" BASE_COLOR << std::endl;
}

Fixed::Fixed(const float num) {
	this->_num = (int)roundf(num * (1 << this->_bit));
	std::cout << GREEN "Float constructor called" BASE_COLOR << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	*this = src;
	std::cout << GREEN "Copy constructor called" BASE_COLOR << std::endl;
}

Fixed &Fixed::operator = (const Fixed &rhs) {
	std::cout << GREEN "Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_num = rhs._num;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << YELLOW "Destructor called" BASE_COLOR << std::endl;
}

int	Fixed::getRawBits( void ) const {
	std::cout << CYAN "getRawBits member function called" BASE_COLOR << std::endl;
	return (this->_num);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << CYAN "setRawBits member function called" BASE_COLOR << std::endl;
	this->_num = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float)this->_num / (float)(1 << this->_bit));
}

int	Fixed::toInt( void ) const {
	return (this->_num / (1 << this->_bit));
}

std::ostream& operator << (std::ostream& os, const Fixed& Fixed) {
	os << Fixed.toFloat();
	return (os);
}
