/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:58:07 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:12:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const std::string &target );
	ShrubberyCreationForm( const ShrubberyCreationForm &src );
	ShrubberyCreationForm &operator = ( const ShrubberyCreationForm &rhs );
	~ShrubberyCreationForm( void );

	virtual void	execute(Bureaucrat const &executor) const;
private:
	std::string	_target;
};

#endif //SHRUBBERYCREATIONFORM_HPP
