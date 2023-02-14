/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:28:43 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/06 14:15:49 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>	// pour std::ptrdiff_t. Used for pointer arithmetic and array indexing. std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.

/* A Random Access Iterator is an iterator that provides both increment and decrement, and that also provides
constant-time methods for moving forward and backward in arbitrary-sized steps. Random Access Iterators provide
essentially all of the operations of ordinary C pointer arithmetic. */


/* Random-access iterators are iterators that can be used to access elements at an arbitrary
offset position relative to the element they point to, offering the same functionality as pointers.
Random-access iterators are the most complete iterators in terms of functionality. All pointer
types are also valid random-access iterators. Iterator algorithms do not depend on the container type.
As the iterators provide common usage for all of them, the internal structure of a container does not matter.*/

namespace ft
{
	template< class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	struct iterator
	{
		typedef Category	iterator_category;	// the category of the iterator. Must be one of iterator category tags.
		typedef T			value_type;			// the type of the values that can be obtained by dereferencing the iterator. This type should be void for output iterators.
		typedef Distance	difference_type;	// a type that can be used to identify distance between iterators 
		typedef Pointer		pointer;			// defines a pointer to the type iterated over (T) 
		typedef Reference	reference;			// defines a reference to the type iterated over (T)
	};

	struct input_iterator_tag {};

	struct output_iterator_tag {};

	struct forward_iterator_tag : public input_iterator_tag {};

	struct bidirectional_iterator_tag : public forward_iterator_tag {};

	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template< typename T >
	class random_access_iterator : public ft::iterator< ft::random_access_iterator_tag, T >
	{
		public:
			typedef T											value_type;
			typedef T& 											reference;
			typedef T* 											pointer;
			typedef const T& 									const_reference;
			typedef const T* 									const_pointer;
			typedef std::ptrdiff_t 								difference_type;
			typedef std::size_t 								size_type;
			typedef typename ft::random_access_iterator_tag		iterator_category;

		private:
			pointer _ptr;

		public:
		//--------------------------------------------------------------------//
		//                                COPLIEN                             //
		//--------------------------------------------------------------------//
			random_access_iterator()
				: _ptr(0){};

			random_access_iterator(pointer ptr)
				: _ptr(ptr){};

			random_access_iterator(random_access_iterator<T> const &cpy)
				: _ptr(cpy._ptr){};

			virtual ~random_access_iterator(){};

			random_access_iterator &operator=(random_access_iterator<T> const &cpy)
			{
				if (this != &cpy)
					_ptr = cpy._ptr;
				return (*this);
			};

			// if trying to copy a const_iterator based on a iterator
			operator random_access_iterator<T const>() const
			{
				return random_access_iterator<T const>(_ptr);
			};

			pointer base() const
			{
				return _ptr;
			};

		//--------------------------------------------------------------------//
		//                        RELATIONAL OPERATOR                         //
		//--------------------------------------------------------------------//

			// relational operator
			bool operator==(const random_access_iterator &src) const
			{
				return _ptr == src._ptr;
			};

			bool operator!=(const random_access_iterator &src) const
			{
				return _ptr != src._ptr;
			};

			pointer operator->()
			{
				return (_ptr);
			};

			reference operator*()
			{
				return (*_ptr);
			};

			bool operator>(const random_access_iterator &src) const
			{
				return _ptr > src._ptr;
			};

			bool operator>=(const random_access_iterator &src) const
			{
				return _ptr >= src._ptr;
			};

			bool operator<(const random_access_iterator &src) const
			{
				return _ptr < src._ptr;
			};

			bool operator<=(const random_access_iterator &src) const
			{
				return _ptr <= src._ptr;
			};

			// relational operator between const and non const iterator
			// must be friend to access protected _ptr in non membre functions
			template <class Ite1, class Ite2>
			friend bool operator==(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs);

			template <class Ite1, class Ite2>
			friend bool operator!=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs);

			template <class Ite1, class Ite2>
			friend bool operator>(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs);

			template <class Ite1, class Ite2>
			friend bool operator>=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs);

			template <class Ite1, class Ite2>
			friend bool operator<(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs);

			template <class Ite1, class Ite2>
			friend bool operator<=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs);

		//--------------------------------------------------------------------//
		//                        INCREMENT / DECREMENT                       //
		//--------------------------------------------------------------------//

			random_access_iterator &operator++() // pre-increment
			{
				_ptr++;
				return (*this);
			};

			random_access_iterator operator++(int) // post-increment
			{
				random_access_iterator tmp = *this;
				_ptr++;
				return (tmp);
			};

			random_access_iterator &operator--() // pre-decrement
			{
				_ptr--;
				return (*this);
			};

			random_access_iterator operator--(int) // post-decrement
			{
				random_access_iterator tmp = *this;
				_ptr--;
				return (tmp);
			};

		//--------------------------------------------------------------------//
		//                       ADDITION / SOUSTRACTION                      //
		//--------------------------------------------------------------------//

			// simple (+/-)
			random_access_iterator operator+(difference_type n) const
			{
				return (_ptr + n);
			};

			random_access_iterator operator-(difference_type n) const
			{
				return (_ptr - n);
			};

			/*
					difference_type operator-(random_access_iterator const &src) const
					{
						return _ptr - src._ptr;
					};
			*/

			// ternaire (+=/-=)
			random_access_iterator &operator+=(difference_type n)
			{
				_ptr += n;
				return *this;
			};

			random_access_iterator &operator-=(difference_type n)
			{
				_ptr -= n;
				return *this;
			};

			reference operator[](difference_type n) const
			{
				return (_ptr[n]);
			};
	}; // END of Class random_access_iterator

	//--------------------------------------------------------------------//
	//                        OVERLOAD OPERATOR                           //
	//--------------------------------------------------------------------//

	// arithmetic operators
	template <class T>
	ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, ft::random_access_iterator<T> const &rhs)
	{
		return rhs + n;
	};

	template <typename T, typename U>
	ptrdiff_t operator-(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
	{
		return (lhs.base() - rhs.base());
	};

	// comparison iterators
	template <typename Ite1, typename Ite2>
	bool operator==(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator!=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator<(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator>(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr > rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator>=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator<=(const random_access_iterator<Ite1> &lhs, const random_access_iterator<Ite2> &rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	};

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

#endif /* RANDOM_ACCESS_ITERATOR_HPP */