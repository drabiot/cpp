/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:14:10 by tchartie          #+#    #+#             */
/*   Updated: 2025/01/16 01:01:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "KyokaSuigetsu.hpp"
#include "GetsugaTensho.hpp"

typedef unsigned int uint;

static void separator(const std::string &title = "END");

int	main()
{
	 //Subject main
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	IMateriaSource	*universalSpellBook = new MateriaSource;

	separator("Universal Spell Book");
	{
		AS_SPELLBOOK(universalSpellBook)->print();

		universalSpellBook->learnMateria(new Cure());
		universalSpellBook->learnMateria(new Ice());
		universalSpellBook->learnMateria(new KyokaSuigetsu());
		universalSpellBook->learnMateria(new GetsugaTensho());

		AS_SPELLBOOK(universalSpellBook)->print();
	}
	separator();

	separator("Basic Character tests");
	{
		ICharacter *bob = new Character("Bob");
		ICharacter *jim = new Character("Jim");
		ICharacter *aizen = new Character("Sosuke Aizen");
		ICharacter *ichigo = new Character;

		std::cout << "I am " << bob->getName() << std::endl;
		std::cout << "I am " << jim->getName() << std::endl;
		std::cout << "I am " << ichigo->getName() << std::endl;
		std::cout << "I am " << aizen->getName() << std::endl;

		bob->equip(universalSpellBook->createMateria("ice"));
		jim->equip(universalSpellBook->createMateria("completely broken spell"));
		jim->equip(universalSpellBook->createMateria("cure"));
		ichigo->equip(universalSpellBook->createMateria("getsuga tensho"));
		aizen->equip(universalSpellBook->createMateria("kyoka suigetsu"));

		bob->use(0, *jim);
		jim->use(0, *bob);
		jim->use(1, *bob);
		ichigo->use(0, *aizen);
		try {
			ichigo->use(1, *aizen);
		} catch (std::exception &e) {
			aizen->use(0, *ichigo);
		}

		delete aizen;
		delete ichigo;
		delete bob;
		delete jim;
	}
	separator();

	separator("Breaking a MateriaSource");
	{
		IMateriaSource *badBook = new MateriaSource(*AS_SPELLBOOK(universalSpellBook));
		AMateria *newSpell = new Cure;

		AS_SPELLBOOK(badBook)->print("Bad Book");
		for (int i = 0; i < 150; ++i) {
			badBook->learnMateria(newSpell);
		}
		AS_SPELLBOOK(badBook)->print("Bad Book");

		delete badBook;
	}
	separator();

	separator("Breaking Characters");
	{
		ICharacter *ichigo = new Character("Ichigo Kurosaki");
		ICharacter *aizen = new Character("Aizen Sosuke");

		std::cout << "I am " << ichigo->getName() << std::endl;

		for (int i = 0; i < 4; ++i) {
			ichigo->equip(universalSpellBook->createMateria("getsuga tensho"));
			ichigo->use(i, *aizen);
			aizen->use(i, *ichigo);
		}
		std::cout << std::endl;
		for (int i = 0; i < 4; ++i) {
			ichigo->unequip(i);
		}
		for (int i = 0; i < 4; ++i) {
			ichigo->unequip(i);
		}
		for (int i = 0; i < 4; ++i) {
			try {
				ichigo->use(i, *aizen);
			} catch (...) {}
			ichigo->equip(universalSpellBook->createMateria("getsuga tensho"));
			ichigo->use(i, *aizen);
			std::cout << std::endl;
		}

		delete aizen;
		delete ichigo;
	}
	separator();

	delete universalSpellBook;

	AMateria::unleak();
}

static void separator(const std::string &title) {
	uint length = (60 - title.length()) / 2;
	std::cout << std::endl;
	std::cout << BASE_COLOR;
	for (uint i = 0; i < length; ++i) {
		std::cout << "-";
	}
	std::cout << "[ ";
	std::cout << title;
	std::cout << " ]";
	if (!(title.length() % 2))
		length--;
	for (uint i = 0; i < length; ++i) {
		std::cout << "-";
	}
	std::cout << std::endl << std::endl;
}
