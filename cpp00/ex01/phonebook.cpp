/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:13:15 by tchartie          #+#    #+#             */
/*   Updated: 2024/11/11 21:19:27 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <cstdlib>
#include <iomanip>

// Constructor
PhoneBook::PhoneBook()
{
    _index = 0;
}

// Destructor
PhoneBook::~PhoneBook()
{
}

static std::string display_format(std::string info)
{
    std::string final_info;

    std::cout << std::setw(10);
    if (info.length() <= 10)
        final_info = info;
    else {
        final_info = info;
        final_info.resize(9);
        final_info += ".";
    }
    return (final_info);
}

void    PhoneBook::searchContact()
{
    std::cout << "|  index   |first name|last  name| nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    for (size_t i = 0; i < 8; i++) {
        std::cout << "|" << std::setw(10) << i << "|";
        std::cout << display_format(_contacts[i].getFirstName()) << "|";
        std::cout << display_format(_contacts[i].getLastName()) << "|";
        std::cout << display_format(_contacts[i].getNickname()) << "|" << std::endl;
    }
    displayContact();
}

void    PhoneBook::displayContact()
{
    std::string	contact;
    int			index = 10;
    bool		error = true;
    
	if (_contacts[0].getFirstName().empty() || _contacts[0].getLastName().empty()
        || _contacts[0].getNickname().empty() || _contacts[0].getPhoneNumber().empty()
            || _contacts[0].getDarkestSecret().empty()) {
		std::cout << std::endl << "NO CONTACT TO DISPLAY" << std::endl;
		return ;
	}
    std::cout << std::endl << "ENTER INDEX OF THE CONTACT YOU WANT TO SEARCH:" << std::endl;
    std::cout << "> ";
    std::getline(std::cin, contact);
    while (error && !std::cin.eof()) {
        while (contact.empty() && !std::cin.eof()) {
			error = true;
            std::cout << "NEED TO FILL THE FIELD" << std::endl << "> ";
            std::getline(std::cin, contact);
        }
        index = std::atoi(contact.c_str());
        if (index > 7 || index < 0) {
			error = true;
            std::cout << "INVALID INDEX: 0-7" << std::endl << "> ";
            std::getline(std::cin, contact);
        }
        else if (_contacts[index].getFirstName().empty() || _contacts[index].getLastName().empty()
            || _contacts[index].getNickname().empty() || _contacts[index].getPhoneNumber().empty()
                || _contacts[index].getDarkestSecret().empty()) {
			error = true;
            std::cout << "CONTACT DOESN'T EXIST" << std::endl << "> ";
            std::getline(std::cin, contact);
        }
		else
			error = false;
    }
    if (std::cin.eof())
        return ;
    std::cout << std::endl;
    std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl << std::endl; 
}

const static std::string phoneBookInfo[] = {"firstName", "lastName", "nickname", "phoneNumber", "darkestSecret"};

static bool    is_valid_phone_number(std::string phoneNumber)
{
    std::string::iterator begin = phoneNumber.begin();

    if (phoneNumber.length() < 2)
        return (false);
    if (phoneNumber[0] == '+')
        begin++;
    for (std::string::iterator iter = begin ;iter != phoneNumber.end(); iter++) {
            if (!std::isdigit(*iter) && *iter != ' ' && *iter != '.' && *iter != '-')
                return (false);
    }
    return (true);
}

static std::string    askInfoContact(std::string info)
{
    size_t i = 0;
    std::string    content;

    if (std::cin.eof())
        return "";
    for (; i < 5; i++)
        if (!info.compare(phoneBookInfo[i]))
        break;
    switch (i)
    {
        case 0: {
            std::cout << "First Name: ";
            std::getline(std::cin, content);
            break;
        }
        case 1: {
            std::cout << "Last Name: ";
            std::getline(std::cin, content);
            break;
        }
        case 2: {
            std::cout << "Nickame: ";
            std::getline(std::cin, content);
            break;
        }
        case 3: {
            std::cout << "Phone Number: ";
            std::getline(std::cin, content);
            while (!is_valid_phone_number(content) && !std::cin.eof()) {
                std::cout << "INVALID PHONE NUMBER" << std::endl;
                std::cout << "Phone Number: ";
                std::getline(std::cin, content);
            }
            break;
        }
        case 4: {
            std::cout << "Darkest Secret: ";
            std::getline(std::cin, content);
            break;
        }
        default: {
            return (NULL);
        }
    }
    if (content.empty() && !std::cin.eof()) {
        std::cout << "NEED TO FILL THE FIELD" << std::endl;
        content = askInfoContact(info);
    }
    return (content);
}

void    PhoneBook::addInfoContact(std::string info, std::string content)
{
    size_t         i;

    for (i = 0; i < 5; i++)
        if (!info.compare(phoneBookInfo[i]))
        break;
    switch (i)
    {
        case 0: {
            _contacts[_index].setFirstName(content);
            break;
        }
        case 1: {
            _contacts[_index].setLastName(content);
            break;
        }
        case 2: {
            _contacts[_index].setNickname(content);
            break;
        }
        case 3: {
            _contacts[_index].setPhoneNumber(content);
            break;
        }
        case 4: {
            _contacts[_index].setDarkestSecret(content);
            break;
        }
        default: {
            return ;
        }
    }
}

void    PhoneBook::addNewContact()
{
    std::string    content;

    std::cout << "ENTER YOUR INFORMATIONS: " << std::endl;
    for (size_t i = 0; i < 5; i++) {
        content = askInfoContact(phoneBookInfo[i]);
        addInfoContact(phoneBookInfo[i], content);
    }
    if (_index >= 7)
        this->_index = 0;
    else
        this->_index++;
}