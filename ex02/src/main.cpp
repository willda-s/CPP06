/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:43:11 by williamguer       #+#    #+#             */
/*   Updated: 2026/07/12 16:09:24 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int random = std::rand() % 3;

    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::bad_cast&) {}
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Base* basePtr = generate();
    std::cout << "Identifying with pointer: ";
    identify(basePtr);

    std::cout << "Identifying with reference: ";
    identify(*basePtr);

    delete basePtr;
    return 0;
}

/*
Dans le main, Srand est utilisé pour initialiser le générateur de nombres aléatoires avec une valeur basée sur l'heure actuelle. 
Cela garantit que les résultats seront différents à chaque exécution du programme. 

Dynamic cast est utilisé pour identifier le type réel de l'objet pointé par un pointeur ou une référence de type Base.
Ici, (void)dynamic_cast<A*>(p) tente de convertir le pointeur p en un pointeur de type A. Si la conversion réussit, cela signifie que l'objet pointé par p est de type A, et "A" est affiché.
Si la conversion échoue, une exception std::bad_cast est levée, qui est attrapée et ignorée, permettant au programme de continuer à tester les autres types (B et C).
(void) est utilisé pour indiquer que le résultat de dynamic_cast n'est pas utilisé directement, mais que l'opération est effectuée uniquement pour vérifier le type de l'objet.
*/