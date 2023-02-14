/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:22:25 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/06 20:31:29 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "iterator.hpp"
# include "pair.hpp"
# include <functional>

namespace ft
{
	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type ret = 0;
		while (first != last)
		{
			first++;
			ret++;
		}
		return ret;
	};

	template <class value_type>
	struct Tnode
	{
		public:
			value_type 		pair;
			Tnode			*right;
			Tnode			*left;
			Tnode			*parent;

			Tnode():
				pair(), right(NULL), left(NULL), parent(NULL) {}
			Tnode(value_type const &val):
				pair(val), right(NULL), left(NULL), parent(NULL) {}
			// Tnode(Tnode const &other):
				// pair(other.pair), right(NULL), left(NULL), parent(NULL) {}
	};

	template <class T>
	struct less : public std::binary_function <T,T,bool>
	{
		bool operator() (const T& x, const T& y) const
		{
			return (x < y);
		};
	};
}

#endif /* UTILS_HPP */