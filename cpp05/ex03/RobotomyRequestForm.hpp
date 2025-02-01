/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:58:02 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/29 21:11:57 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( const std::string &target );
	RobotomyRequestForm( const RobotomyRequestForm &src );
	RobotomyRequestForm &operator = ( const RobotomyRequestForm &rhs );
	~RobotomyRequestForm( void );

	virtual void	execute(Bureaucrat const &executor) const;
private:
	std::string	_target;
};

#endif //ROBOTOMYREQUESTFORM_HPP
