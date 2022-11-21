/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:34:14 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/09 13:14:06 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

/* prototype de base :	template< class T >
						struct is_integral;*/

/* Checks whether T is an integral type. 
Provides the member constant value which is equal to true, if T is the type bool, char, 
char8_t (since C++20), char16_t, char32_t, wchar_t, short, int, long, long long, double, 
long double, float or any implementation-defined extended integer types, including any
signed, unsigned, and cv-qualified variants. Otherwise, value is equal to false. */

namespace ft
{
	/* Si type T n'est pas un integral */
	template<typename T>
	struct is_integral
	{
		static const bool value = false;
	};

	/* Pour les differents types d'integral valides (et leur version const)*/
	
	// ----- bool & const
	template<>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const bool>
	{
		static const bool value = true;
	};

	// ----- char, const & unsigned
	template<>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned char>
	{
		static const bool value = true;
	};
	
	// ----- int, const & unsigned
	template<>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned int>
	{
		static const bool value = true;
	};
	
	// ----- long, const & unsigned
	template<>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned long>
	{
		static const bool value = true;
	};
	
	// ----- long long, const & unsigned
	template<>
	struct is_integral<long long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const long long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long long>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned long long>
	{
		static const bool value = true;
	};
	
	// ----- short, const & unsigned
	template<>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const short>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned short>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned short>
	{
		static const bool value = true;
	};

	// ----- double, const
	template<>
	struct is_integral<double>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const double>
	{
		static const bool value = true;
	};

	// ----- long double, const
	template<>
	struct is_integral<long double>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const long double>
	{
		static const bool value = true;
	};

	// ----- float, const
	template<>
	struct is_integral<float>
	{
		static const bool value = true;
	};

	template<>
	struct is_integral<const float>
	{
		static const bool value = true;
	};
}

#endif /* IS_INTEGRAL_HPP */