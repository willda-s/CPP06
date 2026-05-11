/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:35:34 by williamguer       #+#    #+#             */
/*   Updated: 2026/04/18 17:35:55 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;
    data.value = 42;

    std::cout << "Original Data value: " << data.value << std::endl;

    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << serialized << std::endl;

    Data* deserialized = reinterpret_cast<Data*>(Serializer::deserialize(serialized));
    std::cout << "Deserialized Data value: " << deserialized->value << std::endl;

    return 0;
}
