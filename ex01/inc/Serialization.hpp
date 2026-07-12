/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:28:28 by williamguer       #+#    #+#             */
/*   Updated: 2026/07/12 16:07:54 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <stdint.h>

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