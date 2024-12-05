/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:02:07 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/05 19:38:21 by tchartie         ###   ########.fr       */
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

Fixed::~Fixed() {
	std::cout << YELLOW "Destructor called" BASE_COLOR << std::endl;
}

Fixed	&Fixed::operator = (const Fixed &rhs) {
	std::cout << GREEN "Copy assignment operator called" BASE_COLOR << std::endl;
	if (this == &rhs)
		return (*this);
	this->_num = rhs._num;
	return (*this);
}

//	Arithmetic operators :

Fixed	Fixed::operator + (const Fixed &rhs) const {
	return (this->_num + rhs._num) / (float)(1 << this->_bit);
}

Fixed	Fixed::operator - (const Fixed &rhs) const {
	return (this->_num - rhs._num) / (float)(1 << this->_bit);
}

Fixed	Fixed::operator * (const Fixed &rhs) const {
	return ((this->_num * rhs._num) / (float)(1 << this->_bit * 2));
}

Fixed	Fixed::operator / (const Fixed &rhs) const {
	return (((float)this->_num / (float)rhs._num));
}

//	Comparasion operators :

bool	Fixed::operator > (const Fixed &rhs) const {
	return (this->_num > rhs._num);
}

bool	Fixed::operator < (const Fixed &rhs) const {
	return (this->_num < rhs._num);
}

bool	Fixed::operator >= (const Fixed &rhs) const {
	return (this->_num >= rhs._num);
}

bool	Fixed::operator <= (const Fixed &rhs) const {
	return (this->_num <= rhs._num);
}

bool	Fixed::operator == (const Fixed &rhs) const {
	return (this->_num == rhs._num);
}

bool	Fixed::operator != (const Fixed &rhs) const {
	return (this->_num != rhs._num);
}

//	Increment/Decrement operators :

Fixed	&Fixed::operator ++ () {
	this->_num++;
	return (*this);
}

Fixed	Fixed::operator ++ (int) {
	Fixed	tmp = *this;
	++*this;
	return (tmp);
}

Fixed	&Fixed::operator -- () {
	this->_num--;
	return (*this);
}

Fixed	Fixed::operator -- (int) {
	Fixed	tmp = *this;
	--*this;
	return (tmp);
}

Fixed &Fixed::min (Fixed &num1, Fixed &num2) {
	return (num1 < num2 ? num1 : num2);
}

const Fixed &Fixed::min (const Fixed &num1, const Fixed &num2) {
	return (num1 < num2 ? num1 : num2);
}

Fixed &Fixed::max (Fixed &num1, Fixed &num2) {
	return (num1 > num2 ? num1 : num2);
}

const Fixed &Fixed::max (const Fixed &num1, const Fixed &num2) {
	return (num1 > num2 ? num1 : num2);
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
