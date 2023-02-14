/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:07:22 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/06 16:30:48 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

# include <cstddef>	// pour std::ptrdiff_t. Used for pointer arithmetic and array indexing. std::ptrdiff_t is the signed integer type of the result of subtracting two pointers.
# include "iterator.hpp"
# include "utils.hpp"

namespace ft
{
	/* iterator for map */

	template< typename T >
	class map_iterator
	{
		public:

			typedef T														value_type;
			typedef T*														pointer;			
			typedef T&														reference;

			typedef Tnode<T>*												node_ptr;
			// typedef node<T>*												node_tree;

			typedef typename iterator_traits<node_ptr>::difference_type		difference_type;
			typedef ft::bidirectional_iterator_tag							iterator_category;

			node_ptr														ptr;

		//--------------------------------------------------------------------//
		//                                COPLIEN                             //
		//--------------------------------------------------------------------//
		
		/* default constructor */
			map_iterator() : ptr(NULL) {}

		/* param constructor */
			// explicit map_iterator(node_tree node) : ptr(node) {}
			explicit map_iterator(node_ptr node) : ptr(node) {}


		/* copy constructor */
			map_iterator(const map_iterator &other) : ptr(other.ptr) {}
		
		/* overload operator= */
			map_iterator &operator=(const map_iterator &other)
			{
				ptr = other.ptr;
				return (*this);
			}
		
		/* destructor */
			virtual ~map_iterator(void) { return; }

		//--------------------------------------------------------------------//
		//                          MEMBER FUNCTIONS                          //
		//--------------------------------------------------------------------//

		// ----- ptr / ref

			node_ptr as_ptr(void)
			{
				return (this->ptr);
			}

			pointer operator->() const
			{
				return &(this->ptr->pair);
			}

			reference operator*() const
			{
				return (this->ptr->pair);
			}

		// ----- increment / decrement

			map_iterator &operator++() // pre-increment
			{
				node_ptr	next;

				if (!ptr)
					return (*this);
				/* si on n'a pas de right element */
				if (ptr->right == NULL)
				{
					next = ptr;
					/* on remonte les parents jusqu'à avoir une connection gauche */
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
					ptr = next;
					return (*this);
				}
				/* si on a un right element : 1 x à droite puis tout à gauche */
				next = ptr->right;
				while (next && next->left)
					next = next->left;
				ptr = next;
				return (*this);
			}

			map_iterator operator++(int) // post-increment
			{
				map_iterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			map_iterator &operator--() // pre-decrement
			{
				// node_tree tmp = ptr;
				node_ptr tmp = ptr;

				if (!tmp)
					return (*this);
				/* si on a un left element */
				if (tmp->left)
				{
					/* get further right of left-hand element */
					tmp = tmp->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
					this->ptr = tmp;
					return (*this);
				}
				/* si on a pas de left element : remonter les parents jusqu'à avoir une connection droite */
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				tmp = tmp->parent;
				ptr = tmp;
				return (*this);
			}

			map_iterator operator--(int) // post-decrement
			{
				map_iterator tmp(*this);
				this->operator--();
				return (tmp);
			}

		// ----- equal / different

			bool operator==(const map_iterator &rhs) const
			{
				return (this->ptr == rhs.ptr);
			}

			bool operator!=(const map_iterator &rhs) const
			{
				return (this->ptr != rhs.ptr);
			}
	};

	/* const iterator for map */
	
	template< class T >
	class const_map_iterator
	{
		public:

			typedef T														value_type;
			typedef const value_type*										pointer;			
			typedef const value_type&										reference;

			typedef Tnode<T>*												node_ptr;
			// typedef node<T>*												node_tree;

			typedef typename iterator_traits<node_ptr>::difference_type		difference_type;
			typedef ft::bidirectional_iterator_tag							iterator_category;

			node_ptr														ptr;

		//--------------------------------------------------------------------//
		//                                COPLIEN                             //
		//--------------------------------------------------------------------//
		
		/* default constructor */
			const_map_iterator() : ptr(NULL) {}

		/* param constructor */
			// explicit const_map_iterator(node_tree node) : ptr(node) {}
			explicit const_map_iterator(node_ptr node) : ptr(node) {}

		/* copy constructor */
			template <class U>
			const_map_iterator(const map_iterator<U> &other) : ptr(other.ptr) {}
		
		/* overload operator= */
			template <class U>
			const_map_iterator &operator=(const map_iterator<U> &other)
			{
				this->ptr = other.ptr;
				return (*this);
			}
		
		/* destructor */
			virtual ~const_map_iterator(void) { return; }

		//--------------------------------------------------------------------//
		//                          MEMBER FUNCTIONS                          //
		//--------------------------------------------------------------------//

		// ----- ptr / ref

			node_ptr as_ptr(void) const
			{
				return (this->ptr);
			}

			pointer operator->() const
			{
				return &(this->ptr->pair);
			}

			reference operator*() const
			{
				return (this->ptr->pair);
			}

		// ----- increment / decrement

			const_map_iterator &operator++() // pre-increment
			{
				node_ptr	next;

				if (!ptr)
					return (*this);
				/* si on n'a pas de right element */
				if (ptr->right == NULL)
				{
					next = ptr;
					/* on remonte les parents jusqu'à avoir une connection gauche */
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
					ptr = next;
					return (*this);
				}
				/* si on a un right element : 1 x à droite puis tout à gauche */
				next = ptr->right;
				while (next->left)
					next = next->left;
				ptr = next;
				return (*this);
			}

			const_map_iterator operator++(int) // post-increment
			{
				const_map_iterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			const_map_iterator &operator--() // pre-decrement
			{
				// node_tree tmp = ptr;
				node_ptr tmp = ptr;

				if (!tmp)
					return (*this);
				/* si on a un left element */
				if (tmp->left)
				{
					/* get further right of left-hand element */
					tmp = tmp->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
					this->ptr = tmp;
					return (*this);
				}
				/* si on a pas de left element : remonter les parents jusqu'à avoir une connection droite */
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				tmp = tmp->parent;
				ptr = tmp;
				return (*this);
			}

			const_map_iterator operator--(int) // post-decrement
			{
				const_map_iterator tmp(*this);
				this->operator--();
				return (tmp);
			}

		// ----- equal / different

			bool operator==(const const_map_iterator &rhs) const
			{
				return (this->ptr == rhs.ptr);
			}

			bool operator!=(const const_map_iterator &rhs) const
			{
				return (this->ptr != rhs.ptr);
			}
		
		// ----- iterator to pointer
	};

	//--------------------------------------------------------------------//
	//                        OVERLOAD OPERATOR                           //
	//--------------------------------------------------------------------//

	// arithmetic operators
	template <class T>
	ft::map_iterator<T> operator+(typename ft::map_iterator<T>::difference_type n, ft::map_iterator<T> const &rhs)
	{
		return rhs + n;
	};

	template <typename T, typename U>
	ptrdiff_t operator-(const map_iterator<T> &lhs, const map_iterator<U> &rhs)
	{
		return (lhs.base() - rhs.base());
	};

	// comparison iterators
	template <typename Ite1, typename Ite2>
	bool operator==(const map_iterator<Ite1> &lhs, const map_iterator<Ite2> &rhs)
	{
		return (lhs._ptr == rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator!=(const map_iterator<Ite1> &lhs, const map_iterator<Ite2> &rhs)
	{
		return (lhs._ptr != rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator<(const map_iterator<Ite1> &lhs, const map_iterator<Ite2> &rhs)
	{
		return (lhs._ptr < rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator>(const map_iterator<Ite1> &lhs, const map_iterator<Ite2> &rhs)
	{
		return (lhs._ptr > rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator>=(const map_iterator<Ite1> &lhs, const map_iterator<Ite2> &rhs)
	{
		return (lhs._ptr >= rhs._ptr);
	};

	template <typename Ite1, typename Ite2>
	bool operator<=(const map_iterator<Ite1> &lhs, const map_iterator<Ite2> &rhs)
	{
		return (lhs._ptr <= rhs._ptr);
	};
}

#endif /* ITERATOR_MAP_HPP */