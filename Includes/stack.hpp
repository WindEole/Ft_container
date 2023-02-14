/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:19:26 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/05 14:53:08 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"
# include "lexicographical_compare.hpp"

/* Stacks are a type of container adaptor, specifically designed to operate in a LIFO context
(last-in first-out), where elements are inserted and extracted only from one end of the container. */

namespace ft
{
	template <class T, class UC = vector<T> > // UC = underlying container
	class stack
	{
		protected:
			UC	_uc;

		public:
			typedef UC								container_type;
			typedef typename UC::value_type			value_type;
			typedef typename UC::size_type			size_type;
			// typedef typename UC::reference			reference;
			// typedef typename UC::const_reference	const_reference;

		//--------------------------------------------------------------------//
		//                              COPLIEN                               //
		//--------------------------------------------------------------------//

		/* constructor */
			explicit stack (const UC &ctnr = UC()): _uc(ctnr) {}

		/* destructor */
			virtual ~stack() {}

		/* operator = overload */
			stack& operator=( const stack& other )
			{
				this->_uc = other._uc;
				return (*this);
			}

		//--------------------------------------------------------------------//
		//                          MEMBER FUNCTIONS                          //
		//--------------------------------------------------------------------//

					// empty			OK
					// size				OK
					// top				OK
					// push				OK
					// pop				OK
					// emplace			C11 !
					// swap				C11 !

			bool empty() const // calls member function empty of the underlying container object.
			{
				return (_uc.empty());
			}

			size_type size() const // calls member function size of the underlying container object.
			{
				return (_uc.size());
			}

			value_type& top() // calls member function back of the underlying container object.
			{
				return (_uc.back());
			}

			const value_type& top() const // calls member function back of the underlying container object.
			{
				return (_uc.back());
			}

			void push (const value_type& val) // calls member function push_back of the underlying container object.
			{
				_uc.push_back(val);
			}

			void pop() // calls member function pop_back of the underlying container object.
			{
				_uc.pop_back();
			}


		//--------------------------------------------------------------------//
		//                        RELATIONAL OPERATOR                         //
		//--------------------------------------------------------------------//

		private:

			friend bool operator== (const stack & lhs, const stack & rhs)
			{
				return (lhs._uc == rhs._uc);
			}

			friend bool operator<  (const stack & lhs, const stack & rhs)
			{
				return (lhs._uc < rhs._uc);
			}

	};

		//--------------------------------------------------------------------//
		//                        NON MEMBER FUNCTIONS                        //
		//--------------------------------------------------------------------//

					// relational operators		
					// swap(stack)				C11 !

	template <class T, class Container>
	bool operator!= (const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return (!(lhs < rhs));
	}

	// template <class T, class Container>
	// bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	std::cout << "ICI" << std::endl;
	// 	return (lhs._uc == rhs._uc);
	// }

	// template <class T, class Container>
	// bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (!(lhs._uc == rhs._uc));
	// }

	// template <class T, class Container>
	// bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (ft::lexicographical_compare(lhs._uc.begin(), lhs._uc.end(), rhs._uc.begin(), rhs._uc.end()));
	// }

	// template <class T, class Container>
	// bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (!(lhs.uc > rhs._uc));
	// }

	// template <class T, class Container>
	// bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (rhs.uc < lhs._uc);
	// }

	// template <class T, class Container>
	// bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	// {
	// 	return (!(lhs.uc < rhs._uc));
	// }

}

#endif /* STACK_HPP */