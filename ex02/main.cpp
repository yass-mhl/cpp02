/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:56:08 by ymehlil           #+#    #+#             */
/*   Updated: 2023/07/26 11:28:17 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "a " << a << std::endl;
	std::cout << "++a " << ++a << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "a++ " << a++ << std::endl;
	std::cout << "a " << a << std::endl;
	std::cout << "b " << b << std::endl;
	
	std::cout << "Fixed::max( a, b ) " << Fixed::max( a, b ) << std::endl;
	std::cout << "Fixed::min( a, b ) " << Fixed::min( a, b ) << std::endl;
	a = 2;
	std::cout << "a " << a << std::endl;
	Fixed c( a / Fixed(2));
	std::cout << "c = a / 2 = " << c << std::endl;
	std::cout << "b " << b << std::endl;
	return 0;
}
