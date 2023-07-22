/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:49:41 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/22 20:11:05 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Ajoutez à votre classe les constructeurs et les fonctions membres suivants en public :
	
	• Un constructeur prenant un entier constant en paramètre et qui convertit celuici 
	en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
	comme dans l’exercice 00.
	
	• Un constructeur prenant un flottant constant en paramètre et qui convertit
	celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à
	8 comme dans l’exercice 00.
	
	• Une fonction membre float toFloat( void ) const;
	qui convertit la valeur en virgule fixe en nombre à virgule flottante.
	
	• Une fonction membre int toInt( void ) const;
	qui convertit la valeur en virgule fixe en nombre entier.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &original);
		Fixed(const float value);
		Fixed(const int value);
		~Fixed();
		Fixed& operator=(const Fixed &other);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
	
	private:
		int _value;
		static const int _fractionalBits = 8;

};
	std::ostream& operator<<(std::ostream& os, Fixed const &rhs);
#endif

