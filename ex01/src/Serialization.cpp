/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:34:53 by williamguer       #+#    #+#             */
/*   Updated: 2026/04/18 17:35:06 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer(void)
{
}

uintptr_t Serializer::serialize(void* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

void* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<void*>(raw);
}
