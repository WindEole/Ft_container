/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:22:25 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/08 15:28:05 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "iterator.hpp"

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
}

#endif /* UTILS_HPP */