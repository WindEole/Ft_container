/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:29:50 by iderighe          #+#    #+#             */
/*   Updated: 2022/10/26 12:51:26 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>	// pour std::ptrdiff_t. Used for pointer arithmetic and array indexing.
					// std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.

/* Iterator */

namespace ft
{
	struct input_iterator_tag {};

	// struct forward_iterator_tag {};

	// struct bidirectional_iterator_tag {};

	struct random_access_iterator_tag {};

	template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& > struct iterator
	{
		typedef Category	iterator_category;	// the category of the iterator. Must be one of iterator category tags.
		typedef T			value_type;			// the type of the values that can be obtained by dereferencing the iterator. This type should be void for output iterators.
		typedef Distance	difference_type;	// a type that can be used to identify distance between iterators 
		typedef Pointer		pointer;			// defines a pointer to the type iterated over (T) 
		typedef Reference	reference;			// defines a reference to the type iterated over (T)
	};
}

#endif /* ITERATOR_HPP */