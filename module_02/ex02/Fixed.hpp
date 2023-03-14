/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:32:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/14 20:16:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:

		Fixed(void);
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const &fixed);
		~Fixed(void);

		Fixed&	operator = (Fixed const &fixed);

		bool	operator > (Fixed const & fixed) const;
		bool	operator < (Fixed const & fixed) const;
		bool	operator >= (Fixed const & fixed) const;
		bool	operator <= (Fixed const & fixed) const;
		bool	operator == (Fixed const & fixed) const;
		bool	operator != (Fixed const & fixed) const;

		Fixed	operator + (Fixed const & fixed) const;
		Fixed	operator - (Fixed const & fixed) const;
		Fixed	operator * (Fixed const & fixed) const;
		Fixed	operator / (Fixed const & fixed) const;

		Fixed	operator ++ (void);
		Fixed	operator ++ (int);

		Fixed	operator -- (void);
		Fixed	operator -- (int);

		static Fixed&	min(Fixed& fixed_1, Fixed& fixed_2);
		static Fixed const &	min(Fixed const & fixed_1, Fixed const & fixed_2);
		static Fixed&	max(Fixed& fixed_1, Fixed& fixed_2);
		static Fixed const &	max(Fixed const & fixed_1, Fixed const & fixed_2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int					value;
		static const int	bits;
};

std::ostream & operator<<(std::ostream& o, Fixed const & fixed);

#endif
