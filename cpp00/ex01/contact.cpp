/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:23:46 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/11 20:40:30 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

// Constructor
Contact::Contact()
{
    _firstName		= "";
    _lastName		= "";
    _nickname		= "";
    _phoneNumber	= "";
	_darkestSecret	= "";
}

// Destructor
Contact::~Contact()
{
}

// Getters
std::string	Contact::getFirstName() const {
	return (_firstName);
}

std::string	Contact::getLastName() const {
	return (_lastName);
}

std::string	Contact::getNickname() const {
	return (_nickname);
}

std::string	Contact::getPhoneNumber() const {
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const {
	return (_darkestSecret);
}

// Setters
void	Contact::setFirstName(std::string new_firstName) {
	this->_firstName = new_firstName;
}

void	Contact::setLastName(std::string new_lastName) {
	this->_lastName = new_lastName;
}

void	Contact::setNickname(std::string new_nickname) {
	this->_nickname = new_nickname;
}

void	Contact::setPhoneNumber(std::string new_phoneNumber) {
	this->_phoneNumber = new_phoneNumber;
}

void	Contact::setDarkestSecret(std::string new_darkestSecret) {
	this->_darkestSecret = new_darkestSecret;
}