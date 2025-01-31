/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:59:28 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/31 14:03:38 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm {
public:
	AForm( void );
	AForm( const std::string &name, const size_t &signGrade, const size_t &execGrade );
	AForm( const AForm &src );
	AForm &operator = ( const AForm &rhs );
	virtual ~AForm( void );

	const std::string	getName( void ) const;
	bool				isSigned( void ) const;
	size_t				getSignGrade( void ) const;
	size_t				getExeGrade( void ) const;

	void				beSigned( Bureaucrat &bureaucrat );
	virtual void		execute(Bureaucrat const &executor) const = 0;
protected:
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
	class NotSigned : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class FileError : public std::exception {
	public:
		virtual const char *what() const throw();
	};
private:
	const std::string	_name;
	bool				_signed;
	const size_t		_signGrade;
	const size_t		_execGrade;
};

std::ostream &operator << (std::ostream &os, const AForm &AForm);

#endif //AFORM_HPP
