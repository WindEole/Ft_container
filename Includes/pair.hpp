/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:15:29 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/06 20:06:32 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

/* This class couples together a pair of values, which may be of different types (T and U).
 * The individuals values can be accessed through its public member first and second. */


namespace ft
{
	template<class T, class U>
	class pair
	{
		public:
			typedef T		first_type;
			typedef U		second_type;

			T	first;
			U	second;

		//--------------------------------------------------------------------//
		//                              COPLIEN                               //
		//--------------------------------------------------------------------//

		// default constructor -> constructs a pair object with its elements value_initialized.
			pair() : first(T()), second(U()) {}

		// copy constructor -> the object is initialized with the content of the pr object.
			template<class V, class W>
			pair(const pair<V, W> &pr): first(pr.first), second(pr.second) {} 

		// initialization constructor -> Member first is constructed with a, and member second with b.
			pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		// destructeur
			virtual ~pair() {}

		// operator= overload
			pair &operator= (const pair &pr)
			{
				if (*this == pr)
					return (*this);
				first = pr.first;
				second = pr.second;
				return (*this);
			}
	};

	//----------------------------------------------------------------------//
	//                         NON MEMBER FUNCTIONS                         //
	//----------------------------------------------------------------------//

	/* MAKE_PAIR */

	template <class U, class V>
	ft::pair<U, V> make_pair(U x, V y)
	{
		return ( ft::pair<U, V>(x, y));
	}

	/* NON MEMBER FUNCTION OVERLOADS (relational operator only) */

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
}

#endif /* _PAIR_HPP_ */
