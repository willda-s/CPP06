/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:28:28 by williamguer       #+#    #+#             */
/*   Updated: 2026/04/18 17:34:30 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <cstdint>

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer(void);
    
    public:
        static uintptr_t serialize(void* ptr);
        static void* deserialize(uintptr_t raw);
};

#endif