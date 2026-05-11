/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:37:30 by williamguer       #+#    #+#             */
/*   Updated: 2026/04/18 17:37:40 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void) : value(0)
{
}

Data::Data(const Data& other) : value(other.value)
{
}

Data& Data::operator=(const Data& other)
{
    if (this != &other)
    {
        value = other.value;
    }
    return *this;
}

Data::~Data(void)
{
}
