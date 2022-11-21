/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:32:14 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/21 12:13:26 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESERVE_ITERATOR_HPP
# define RESERVE_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "random_access_iterator.hpp"
# include <cstddef>	// pour std::ptrdiff_t. Used for pointer arithmetic and array indexing.
					// std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.

/* std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator, it produces a new
iterator that moves from the end to the beginning of the sequence defined by the underlying bidirectional iterator. */

namespace ft
{
	template< typename _Iter >
	class reverse_iterator// : public random_access_iterator< _Iter >
	{
		private:
			_Iter _ptr;

		public:
			typedef _Iter													iterator_type;
			typedef typename ft::iterator_traits<_Iter>::iterator_category	category;
			// typedef typename ft::iterator_traits<_Iter>::value_type			value_type;
			typedef typename ft::iterator_traits<_Iter>::difference_type	difference_type;
			typedef typename ft::iterator_traits<_Iter>::pointer			pointer;
			typedef typename ft::iterator_traits<_Iter>::reference			reference;

		public:

		//--------------------------------------------------------------------//
		//                                COPLIEN                             //
		//--------------------------------------------------------------------//

			/* default constructor */
			reverse_iterator() : _ptr(0){};

			/* param constructor */
			explicit reverse_iterator(_Iter ptr) : _ptr(ptr){};

			/* copy constructor */
			template <class T>
			reverse_iterator(const reverse_iterator<T> &cpy) : _ptr(cpy.base()){};

			/* destructor */
			virtual ~reverse_iterator(){};

			/* operator= overload */
			template <class T>
			reverse_iterator &operator=(const reverse_iterator<T> &cpy)
			{
				if (this != &cpy)
					_ptr = cpy.base();
				return (*this);
			}

		//--------------------------------------------------------------------//
		//                               GETTER                               //
		//--------------------------------------------------------------------//

			/* Returns the underlying base iterator. The base iterator refers to the element
			that is next to the element the reverse_iterator is currently pointing to.*/
			_Iter base() const
			{
				return _ptr;
			}

		//--------------------------------------------------------------------//
		//                          MEMBER FUNCTIONS                          //
		//--------------------------------------------------------------------//

			// ----- ptr / ref / index

			pointer operator->()
			{
				_Iter _tmp = _ptr;
				return &(*--_tmp);
			}

			reference operator*() const
			{
				_Iter _tmp = _ptr;
				return (*--_tmp);
			}

			reference operator[](difference_type n)
			{
				return *(*this + n);
			}

			// ----- simple (+/-)

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(_ptr - n);
			}

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(_ptr + n);
			}

			// ----- increment / decrement

			reverse_iterator &operator++() // pre-increment
			{
				_ptr--;
				return (*this);
			}

			reverse_iterator operator++(int) // post-increment
			{
				reverse_iterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			reverse_iterator &operator--() // pre-decrement
			{
				_ptr++;
				return (*this);
			}

			reverse_iterator operator--(int) // post-decrement
			{
				reverse_iterator tmp(*this);
				this->operator--();
				return (tmp);
			}

			// ----- ternaire (+=/-=)

			reverse_iterator &operator+=(difference_type n)
			{
				_ptr -= n;
				return *this;
			}

			reverse_iterator &operator-=(difference_type n)
			{
				_ptr += n;
				return *this;
			}
		};

	//--------------------------------------------------------------------//
	//                      NON MEMBER FUNCTIONS                          //
	//--------------------------------------------------------------------//

		// ----- arithmetic operators - / +

		template <typename T, typename U>
		typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (rhs.base() - lhs.base());
		};

		template <class T>
		reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> &rhs)
		{
			return (rhs + n);
		};

		// ----- comparison iterators (< / > / == / != / >= / <=)

		template <typename Ite1, typename Ite2>
		bool operator==(const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{
			return (lhs.base() == rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator!=(const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator<(const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{
			return (lhs.base() > rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator>(const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{
			return (lhs.base() < rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator>=(const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{
			return (lhs.base() <= rhs.base());
		}

		template <typename Ite1, typename Ite2>
		bool operator<=(const reverse_iterator<Ite1> &lhs, const reverse_iterator<Ite2> &rhs)
		{
			return (lhs.base() >= rhs.base());
		}
}

#endif /* RESERVE_ITERATOR_HPP */                                                                                