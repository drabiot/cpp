/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:28 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/28 00:32:01 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
public:
	Form( void );
	Form( const std::string &name, const size_t &signGrade, const size_t &execGrade );
	Form( const Form &src );
	Form &operator = ( const Form &rhs );
	~Form( void );

	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	size_t				getSignGrade( void ) const;
	size_t				getExeGrade( void ) const;

	void				beSigned( Bureaucrat &bureaucrat );
private:
	class GradeTooHightException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class AlreadySigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};
private:
	const std::string	_name;
	bool				_signed;
	const size_t		_signGrade;
	const size_t		_execGrade;
};

std::ostream &operator << (std::ostream &os, const Form &Form);

#endif //FORM_HPP
