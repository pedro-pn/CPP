/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:05:19 by pedro             #+#    #+#             */
/*   Updated: 2023/03/30 20:20:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "data.hpp"

class Serializer {
	
	public:
	
		~Serializer(void);
		
		Serializer&	operator=(Serializer const &rhs);
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
	private:
	
		Serializer(void);
		Serializer(Serializer const &rhs);
};

#endif
