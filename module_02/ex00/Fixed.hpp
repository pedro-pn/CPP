/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:32:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/06 21:13:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const &fixed);
		~Fixed(void);

		Fixed & operator = (Fixed const &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:

		int					value;
		static const int	bits;
};

#endif
