/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:38:01 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/19 17:46:47 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include "iterator.hpp"
# include "random_access_iterator.hpp"
# include <cstddef>	// pour std::ptrdiff_t. Used for pointer arithmetic and array indexing.
					// std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.

/* std::iterator_traits is the type trait class that provides uniform interface to the properties of
LegacyIterator(Input / Output / Forward / Bidirectional / RandomAccess Iterator...) types.
This makes it possible to implement algorithms only in terms of iterators. */

/* _Iter = the iterator type to retrieve properties for */

namespace ft
{
	/*used for iterator*/
	template< typename _Iter >
	struct iterator_traits
	{
		typedef typename _Iter::iterator_category	iterator_category;
		typedef typename _Iter::value_type			value_type;
		typedef typename _Iter::difference_type		difference_type;
		typedef typename _Iter::pointer				pointer;
		typedef typename _Iter::reference			reference;
	};

	/*used for pointers in reverse_iterator*/	
	template< typename _T >
	struct iterator_traits<_T*>
	{
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef _T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef _T*									pointer;
		typedef _T&									reference;
	};

	/*used for const pointers in reverse_const_iterator*/	
	template< typename _T >
	struct iterator_traits<const _T*>
	{
		typedef ft::random_access_iterator_tag		iterator_category;
		typedef _T									value_type;
		typedef std::ptrdiff_t						difference_type;
		typedef const _T*							pointer;
		typedef const _T&							reference;
	};
}

#endif /* ITERATOR_TRAITS_HPP */