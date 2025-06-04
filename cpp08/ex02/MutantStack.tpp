/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:29:03 by tchartie          #+#    #+#             */
/*   Updated: 2025/06/04 19:52:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack( void ) {
    PRINT GREEN "MutantStack Created" CENDL;
}

template <typename T>
MutantStack<T>::MutantStack( cref(MutantStack) src ) {
    *this = src;
    PRINT GREEN "MutantStack Copy constructor operator called" CENDL;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator = ( cref(MutantStack) rhs ) {
    PRINT GREEN "MutantStack Copy assignment operator called" CENDL;
    if (this == &rhs)
		return (*this);
	this->c = rhs.c;
	return (*this);
} 

template <typename T>
MutantStack<T>::~MutantStack( void ) {
    PRINT YELLOW "MutantStack Destroyed" CENDL;
}

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin( void ) {
    return(this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::end( void ) {
    return(this->c.end());
}
