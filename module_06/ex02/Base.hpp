/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:57:28 by pedro             #+#    #+#             */
/*   Updated: 2023/03/30 11:41:31 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	
	public:
	
		virtual ~Base(void);
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
