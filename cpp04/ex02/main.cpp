/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:05:47 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 01:31:03 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << std::endl;

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();

		std::cout << std::endl;

		const WrongAnimal*	k = new WrongCat();

		std::cout << std::endl;

		std::cout << k->getType() << " " << std::endl;

		std::cout << std::endl;
		
		k->makeSound();

		std::cout << std::endl;

		delete j;
		delete i;
		delete k;
	}
	{
		AAnimal **animals = new AAnimal*[20];
		for (std::size_t i = 0; i < 20; i++)
		{
			if (i < 10)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (std::size_t i = 0; i < 20; i++)
		{
			animals[i]->makeSound();
			delete animals[i];
		}
		delete []animals;
	}
	
	return 0;
}
