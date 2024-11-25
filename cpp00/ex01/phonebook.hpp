/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:16:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 08:49:26 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
public:
  PhoneBook(void);  // Constructor
  ~PhoneBook(void); // Destructor

  // Getters
  void  searchContact(void);
  void  displayContact(void);

  // Setters
  void  addNewContact(void);
  void  addInfoContact(std::string info, std::string content);

private:
  int _index;
  Contact _contacts[8];
};

#endif // PHONEBOOK_HPP
