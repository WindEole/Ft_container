/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:35:03 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/23 16:20:51 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	/* A lexicographical comparison is the kind of comparison generally used to sort words alphabetically
	in dictionaries; It involves comparing sequentially the elements that have the same position in both
	ranges against each other until one element is not equivalent to the other. The result of comparing these
	first non-matching elements is the result of the lexicographical comparison. */
	
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		/* on teste si vector 1 < vector 2 !*/
		while (first1 != last1)
		{
			/* if vector 2 is empty OR 1 des valeurs de vector 2 est inférieure à la valeur de vector 1 -> vector 1 est supérieur !*/
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	/* function template equal tests whether the elements in two ranges are equal.
	Compares the elements in the range [first1,last1) with those in the range beginning at first2,
	and returns true if all of the elements in both ranges match.*/

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
}

#endif /* LEXICOGRAPHICAL_COMPARE_HPP */