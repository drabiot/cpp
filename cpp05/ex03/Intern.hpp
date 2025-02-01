/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:16:14 by tchartie          #+#    #+#             */
/*   Updated: 2025/02/01 16:33:55 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
public:
	Intern( void );
	Intern( const Intern &src );
	Intern &operator = ( const Intern &rhs );
	virtual ~Intern( void );

	AForm	*makeForm(std::string name, std::string target);
private:
	class FormError : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

#endif //INTERN_HPP
