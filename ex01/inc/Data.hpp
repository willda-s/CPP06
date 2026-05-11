/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:28:47 by williamguer       #+#    #+#             */
/*   Updated: 2026/04/18 17:38:10 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
    public:
        int value;
        Data(void);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data(void);
};

#endif