/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:02:41 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/27 22:16:06 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "color.hpp"

class	Bureaucrat {
public:
	Bureaucrat( void );
	Bureaucrat( const std::string &name, const int &grade );
	Bureaucrat( const Bureaucrat &src );
	Bureaucrat &operator = ( const Bureaucrat &rhs );
	~Bureaucrat( void );

	const std::string	&getName( void ) const ;
	const size_t 		&getGrade( void ) const ;

	void	promoteBureaucrat( void );
	void	demoteBureaucrat( void );
private:
	class GradeTooHightException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
private:
	const std::string	_name;
	size_t				_grade;
};

std::ostream &operator << (std::ostream &os, const Bureaucrat &Bureacrat);

#endif //BUREAUCRAT_HPP
