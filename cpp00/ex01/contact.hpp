/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:24:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/07/27 23:24:23 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact
{
	public:
		Contact(void);	// Constructor
		~Contact(void);	// Destructor

		// Getters
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
    	std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;

		// Setters
		void	setFirstName(std::string new_firstName);
		void	setLastName(std::string new_lastName);
		void	setNickname(std::string new_Nickname);
		void	setPhoneNumber(std::string new_phoneNumber);
		void	setDarkestSecret(std::string new_darkestSecret);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif //CONTACT_H