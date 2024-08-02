/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:16:23 by tchartie          #+#    #+#             */
/*   Updated: 2024/08/02 08:18:36 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

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

#endif // PHONEBOOK_H