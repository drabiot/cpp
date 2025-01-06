/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:47 by tchartie          #+#    #+#             */
/*   Updated: 2024/12/10 16:42:08 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	met	std::cout << std::endl;

	return 0;dl;

	const WrongAnimal*	k = new WrongCat();

	std::cout << std::endl;

	std::cout << k->getType() << " " << std::endl;

	std::cout << std::endl;
	
	k->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete k;

	return 0;
}
