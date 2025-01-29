/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:57:57 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:11:51 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( const std::string &target );
	PresidentialPardonForm( const PresidentialPardonForm &src );
	PresidentialPardonForm &operator = ( const PresidentialPardonForm &rhs );
	~PresidentialPardonForm( void );

	virtual void	execute(Bureaucrat const &executor) const;
private:
	std::string	_target;
};

#endif //PRESIDENTIALPARDONFORM_HPP
