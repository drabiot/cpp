/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:21:38 by tchartie          #+#    #+#             */
/*   Updated: 2025/04/29 21:22:54 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _array(0), _size(0) {
	try {
		this->_array = new T[0];
	}
	catch(const std::exception& e) {
		throw (e);
	}
}

template <typename T>
Array<T>::Array( unsigned int n ) : _array(0), _size(n) {
	try {
		this->_array = new T[n];
	}
	catch(const std::exception& e) {
		throw (e);
	}
}

template <typename T>
Array<T>::Array( cref(Array) src) : _array(0), _size(src._size) {
	try {
		_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; ++i) {
			this->_array[i] = src._array[i];
		}
	}
	catch(const std::exception& e) {
		throw (e);
	}
}

template <typename T>
Array<T> &Array<T>::operator = ( cref(Array) rhs ) {
	if (this == &rhs)
		return (*this);
	if (this->_size != rhs._size) {
		try {
			delete[] this->_array;
			this->_array = new T[rhs._size];
			this->_size = rhs._size;
		}
		catch(const std::exception& e) {
			throw (e);
		}
	}
	for (unsigned int i = 0; i < this->_size; ++i) {
		this->_array[i] = rhs._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array( void ) {
	delete[] this->_array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
T &Array<T>::operator [] (unsigned int index) {
	if (index >= this->_size) {
		throw outOfRangeException();
	}
	return this->_array[index];
}

template <typename T>
const T &Array<T>::operator [] (unsigned int index) const {
	if (index >= this->_size) {
		throw outOfRangeException();
	}
	return this->_array[index];
}

template <typename T>
std::ostream	&operator<<(std::ostream &out, Array<T> &in)
{
	out << "Array size: " << in.size() << ", Array value: ";
	for (unsigned int i = 0; i < in.size(); i++)
	{
		out << in[i];
		if (i < in.size() - 1)
			out << ", ";
	}
	return (out);
}
