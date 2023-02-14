/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:56:04 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/06 23:55:33 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
#define MAP_HPP

# include <iostream>	// pour std::cout...
#include <functional>	// pour binary_function de la nested class value_compare
#include <memory>		// pour allocator !
#include <typeinfo>		// pour rebind !
#include "utils.hpp"
#include "iterator_map.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include "lexicographical_compare.hpp"

/* Maps are associative containers that store elements formed by a combination
of a key value and a mapped value, following a specific order. */

//---------------------------------------------------------------------

// template <typename T>
// class foo {
// 	public:
// 		typedef T	value_type;

// 		foo(void) : value(), _verbose(false) { };
// 		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
// 		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
// 		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
// 		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
// 		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
// 		foo &operator=(value_type src) { this->value = src; return *this; };
// 		foo &operator=(foo const &src) {
// 			if (this->_verbose || src._verbose)
// 				std::cout << "foo::operator=(foo) CALLED" << std::endl;
// 			this->value = src.value;
// 			return *this;
// 		};
// 		value_type	getValue(void) const { return this->value; };
// 		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

// 		operator value_type(void) const {
// 			return value_type(this->value);
// 		}
// 	private:
// 		value_type	value;
// 		bool		_verbose;
// };

// template <typename T>
// std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
// {
// 	o << "key: " << iterator->first << " | value: " << iterator->second;
// 	if (nl)
// 		o << std::endl;
// 	return ("");
// }

// template <typename T_MAP>
// void	printSize(T_MAP const &mp, bool print_content = 1)
// {
// 	std::cout << "size: " << mp.size() << std::endl;
// 	std::cout << "max_size: " << mp.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << printPair(it, false) << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

//---------------------------------------------------------------------

namespace ft
{
	template < typename Key, typename P, class Compare = ft::less<Key> >
	class Map_compare : public std::binary_function<P, P, bool>
	{
		private: 
			Compare	_comp;

		public:
			Map_compare(Compare const &comp = Compare()) : _comp(comp) {}
			virtual ~Map_compare() {}
			
			bool operator() (const P& x, const P& y) const
			{
				return (_comp(x.first, y.first));
			}

			bool operator() (const P& x, const Key& y) const
			{
				return (_comp(x.first, y));
			}

			bool operator() (const Key& x, const P& y) const
			{
				return (_comp(x, y.first));
			}

			bool operator() (const Key& x, const Key& y) const
			{
				return (_comp(x, y));
			}
	};

	
	//				|-> map::key_type
	//				|		|-> map::mapped_type		|->map::key_compare			|->map::allocator_type
	template < class Key, class T, class Compare = Map_compare< Key, ft::pair<Key, T> >, class Allocator = std::allocator< pair< const Key, T > > >
	class map
	{
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef ft::pair<const key_type, mapped_type>						value_type;
			typedef Compare														key_compare;

			typedef	Allocator				 									allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;

			// typedef typename ft::random_access_iterator<T>						iterator;
			// typedef typename ft::random_access_iterator<const T>				const_iterator;
			typedef typename ft::map_iterator<value_type>						iterator;
			typedef typename ft::const_map_iterator<value_type>					const_iterator;
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef std::ptrdiff_t												difference_type;
			typedef std::size_t													size_type;

			typedef Tnode<value_type>*											node_pointer;
			typedef Tnode<value_type>											node_item;
			/* de base, allocator n'alloue qu'un seul type : pair(key, value). Or, dans nos nodes, on alloue pair + 3 pointeurs*/
			typedef typename Allocator::template rebind<node_item>::other		node_alloc_type;

		protected:
			allocator_type		_alloc;	// ALLOCATEUR DE PAIR!!
			key_compare			_comp;			// COMPARATEUR !!
			size_type			_size;			// nb d'elements dans la map
			node_pointer		_root;			// pointeur vers la root de la map
			node_pointer		_begin;			// pointeur vers le début de la map
			node_pointer		_end;			// pointeur vers la fin de la map
			node_alloc_type		_alloc_node;	// ALLOCATEUR DE NODE !!
			

		public:

		//--------------------------------------------------------------------//
		//                                COPLIEN                             //
		//--------------------------------------------------------------------//

					// Constructors (3)		OK
					// Destructor			OK
					// operator=			OK

		//------------------------- Constructeurs ----------------------------//
		/*Il y a trois constructeurs:

		1) un contructeur par défaut (càd sans argument pour simplement créer la map) 
		2) un constructeur avec une plage d'iterateur a mettre a l'iterieur a l'initalisation
		3) un constructeur par copie

		ATTENTION : The container keeps an internal copy of alloc and comp, which are used
		to allocate storage and to sort the elements throughout its lifetime.
		
		The elements are sorted according to the comparison object. If more than one element
		with equivalent keys is passed to the constructor, only the first one is preserved.*/
		
		// ----- 1) Default constructor. Constructs empty container ----- //
			explicit map( const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type() )
			{
				_alloc = alloc;
				_comp = comp;
				_size = 0;

				/* Attempts to allocate a block of storage with a size large enough to contain n elements of member type
				value_type (an alias of the allocator's template parameter), and returns a pointer to the first element. */
				_root = _alloc_node.allocate(1);

				/* Constructs an element object on the location pointed by p. */
				_alloc_node.construct(_root, node_item());

				_begin = _root;
				_end = _root;
				// std::cout << "Constructeur par défaut : \n- size = " << size() << std::endl; 
			}

		// ----- 2) Constructs the container with the contents of the range [first, last] ----- //
			template< class InputIterator >
			map( InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0 )
			{
				_alloc = alloc;
				_comp = comp;
				_size = 0;
				_root = _alloc_node.allocate(1);
				_alloc_node.construct(_root, node_item());
				_begin = _root;
				_end = _root;

				this->insert(first, last);
				// std::cout << "Constructeur par plage : \n- size = " << size() << std::endl;
			}
			
		// ----- 3) Copy constructor. Constructs the container with the copy of the contents of other. If alloc is not provided, allocator is obtained by calling std::allocator_traits<allocator_type>::select_on_container_copy_construction(other). ----- //
			map( const map& other )
			{
				_size = 0;
				_root = _alloc_node.allocate(1);
				_alloc_node.construct(_root, node_item());
				_alloc = other._alloc;
				_comp = other._comp;
				_begin = _root;
				_end = _root;

				this->insert(other.begin(), other.end());
				// std::cout << "Constructeur par copie LA D-Righetti !!! : \n- size = " << size() << std::endl;
			}
		
		//------------------------- Destructeur ----------------------------//
		/* Destructs the map. The destructors of the elements are called and the used storage is deallocated. 
		Note that if the elements are pointers, the pointed-to objects are not destroyed. */
			virtual ~map(void)
			{
				this->clear();
				this->_alloc_node.deallocate(this->_root, 1);
				// std::cout << "Destructor Called \n----------------------------------------------------------------------------" << std::endl;
			}

		//-------------------------- Operateur = -----------------------------//
		/* Copy assignment operator. Replaces the contents with a copy of the contents of other. the allocator
		of *this is replaced by a copy of that of other. If the allocator of *this after assignment would compare
		unequal to its old value, the old allocator is used to deallocate the memory, then the new allocator
		is used to allocate it before copying the elements. Otherwise, the memory owned by *this may be reused
		when possible. In any case, the elements originally belonging to *this may be either destroyed
		or replaced by element-wise copy-assignment. */
			// vector& operator=( const vector& other )
			// {
			// 	if (this != &other)
			// 	{
			// 		clear();
			// 		assign(other.begin(), other.end());
			// 	}
			// 	return (*this);
			// }
			map& operator= (const map& other)
			{
				if (this != &other)
				{
					this->clear();
					this->insert(other.begin(), other.end());
				}
				return (*this);
			}

		//--------------------------------------------------------------------//
		//                              ITERATORS                             //
		//--------------------------------------------------------------------//

					// begin (normal & const)	OK
					// end (normal & const)		OK
					// rbegin					OK
					// rend						OK
					// cbegin					C11 !
					// cend						C11 !
					// crbegin					C11 !
					// crend					C11 !

			iterator begin()
			{
				return (iterator(this->_begin));
			}

			const_iterator begin() const
			{
				return (const_iterator(this->_begin));
			}

			iterator end()
			{
				return (iterator(this->_end));
			}

			const_iterator end() const
			{
				return (const_iterator(this->_end));
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(iterator(this->_end)));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(const_iterator(this->_end)));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(iterator(this->_begin)));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(const_iterator(this->_begin)));
			}

		//--------------------------------------------------------------------//
		//                               CAPACITY                             //
		//--------------------------------------------------------------------//

					// empty			OK
					// size				OK
					// max_size			OK

			bool empty() const
			{
			/* Returns whether the vector is empty (i.e. whether its size is 0). */
				if (size())
					return (false);
				return (true);
			}

			size_type size() const
			{
				return (this->_size);
			}

			size_type max_size() const
			{
				return (this->_alloc_node.max_size());
			}

		//--------------------------------------------------------------------//
		//                            ELEMENT ACCESS                          //
		//--------------------------------------------------------------------//

					// operator[]						OK
					// at (2 fct : normal & const)		OK

			mapped_type &operator[] (const key_type &k)
			{
			/* If k matches the key of an element in the container, the function returns a reference to its mapped value. */
				return ((this->insert(ft::make_pair(k, mapped_type()))).first->second);
			}

			mapped_type& at (const key_type& k)
			{
				iterator tmp = find(k);
				if (!tmp.as_ptr())
					throw std::out_of_range("map::at -> index out of range !");
				return (tmp->second);
			}
			
			const mapped_type& at (const key_type& k) const
			{
				const_iterator tmp = find(k);
				if (!tmp.as_ptr())
					throw std::out_of_range("map::at -> index out of range !");
				return (tmp->second);
			}

		//--------------------------------------------------------------------//
		//                               MODIFIERS                            //
		//--------------------------------------------------------------------//

					// insert (3 fct : single & fill & range)	OK
					// erase (3 fct : position & key & range)	OK
					// swap										OK
					// clear									OK
					// emplace									C11 !
					// emplace_hint								C11 !

			void def_limits()
			{
				node_pointer it = _root;
				if (this->empty())
					return ;
				while (it->left != NULL)
					it = it->left;
				_begin = it;
				it = _root;
				while (it->right != NULL)
					it = it->right;
				it->right = _end;
				_end->parent = it;
				return ;
			}

			void rec_insert(node_pointer node, node_pointer insert)
			{
				if (_comp(insert->pair.first, node->pair.first))
				{
					if (node->left) {
						rec_insert(node->left, insert);
						return ;
					} 
					node->left = insert;
				}
				else
				{
					if (node->right) {
						rec_insert(node->right, insert);
						return ;
					} 
					node->right = insert;
				}
				insert->parent = node;
			}

			pair<iterator, bool> insert(const value_type& val)
			{
			/* Extends the container by inserting new elements, effectively increasing the
			container size by the number of elements inserted.*/
				if (this->empty())
				{
					_root = _alloc_node.allocate(1);
					_alloc_node.construct(_root, node_item(val));
					_begin = _root;
					_root->right = _end;
					_end->parent = _root;
					_size++;
					return (ft::make_pair(iterator(_root), true));
				}
				iterator check = this->find(val.first);
				if (check != iterator(_end))
					return (ft::make_pair(check, false));
				node_pointer insert = _alloc_node.allocate(1);
				_alloc_node.construct(insert, node_item(val));
				if (_end->parent)
					_end->parent->right = NULL;
				rec_insert(_root, insert);
				_size++;
				def_limits();
				return (ft::make_pair(iterator(insert), true));
			}

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				return (this->insert(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, void **>::type = 0)
			{
				while (first != last)
				{
					// this->insert(*first);
					this->insert(*first);
					first++;
				}
			}

			void erase (iterator position)
			{
			/* Removes from the map container a single element. This effectively reduces the container
			size by the number of elements removed, which are destroyed.*/
				node_pointer pos = position.as_ptr();

				if (this->_end->parent)
					this->_end->parent->right = NULL;
			// 1) no children
				if (!pos->left && !pos->right)
				{
					if (pos == _root)
					{
						_root = _end;
						_begin = _end;
						_end->parent = NULL;
					}
					else if (pos->parent)
					{
						if (pos->parent->right == pos)
							pos->parent->right = NULL;
						if (pos->parent->left == pos)
							pos->parent->left = NULL;
					}
					this->_alloc_node.destroy(position.as_ptr());
					this->_alloc_node.deallocate(position.as_ptr(), 1);
				}
			// 2) one child right
				else if (!pos->left && pos->right)
				{
					if (pos == _root)
					{
						_root = pos->right;
						pos->right->parent = NULL;
					}
					else if (pos->parent)
					{
						if (pos->parent->right == pos)
						{
							pos->parent->right = pos->right;
							pos->right->parent = pos->parent;
						}
						if (pos->parent->left == pos)
						{
							pos->parent->left = pos->right;
							pos->right->parent = pos->parent;
						}
					}
					this->_alloc_node.destroy(position.as_ptr());
					this->_alloc_node.deallocate(position.as_ptr(), 1);
				}
			// 3) one child left
				else if (pos->left && !pos->right)
				{
					if (pos == _root)
					{
						_root = pos->left;
						pos->left->parent = NULL;
					}
					else if (pos->parent)
					{
						if (pos->parent->right == pos)
						{
							pos->parent->right = pos->left;
							pos->left->parent = pos->parent;
						}
						if (pos->parent->left == pos)
						{
							pos->parent->left = pos->left;
							pos->left->parent = pos->parent;
						}
					}
					this->_alloc_node.destroy(position.as_ptr());
					this->_alloc_node.deallocate(position.as_ptr(), 1);
				}
			// 4) two children
				else if (pos->left && pos->right)
				{
					node_pointer min_l = pos->left;
					while (min_l && min_l->right)
						min_l = min_l->right;
					if (min_l->left && min_l->parent != _root)
					{
						if (min_l->parent->right == min_l) {
							min_l->parent->right = min_l->left;
							min_l->left->parent = min_l->parent; }
						if (min_l->parent->left == min_l) {
							min_l->parent->left = min_l->left;
							min_l->left->parent = min_l->parent; }
						min_l->left = pos->left;
						min_l->left->parent = min_l;
					}
					else if (min_l->parent != _root)
					{
						min_l->parent->right = NULL;
						min_l->left = pos->left;
						min_l->left->parent = min_l;
					}
					else if (!min_l->right)
						min_l->right = NULL;
					min_l->right = pos->right;
					min_l->right->parent = min_l;
					if (pos == _root)
						_root = min_l;
					else if (pos->parent)
					{
						min_l->parent = pos->parent;
						if (pos->parent->right == pos)
							pos->parent->right = min_l;
						if (pos->parent->left == pos)
							pos->parent->left = min_l;
					}
					this->_alloc_node.destroy(position.as_ptr());
					this->_alloc_node.deallocate(position.as_ptr(), 1);
				}
				this->_size--;
				def_limits();
			}

			size_type erase(const key_type &k)
			{
				iterator tmp = find(k);
				if (tmp.as_ptr() == _end)
					return (0);
				this->erase(tmp);
				return (1);
			}

			void erase (iterator first, iterator last)
			{
				if (first == this->begin() && last == this->end())
					this->clear();
				else
				{
					while (first != last)
						this->erase(first++);
				}
			}

			void swap (map& x)
			{
			/* Exchanges the content of the container by the content of x, which is another map of the same type.
			Sizes may differ. After the call to this member function, the elements in this container are those which were
			in x before the call, and the elements of x are those which were in this. All iterators, references and pointers
			remain valid for the swapped objects. */

			/* ATTENTION : All iterators, pointers and references referring to elements in both containers remain valid, and are now
			referring to the same elements they referred to before the call, but in the other container, where they now iterate !*/

				node_pointer tmp_root = x._root;
				x._root = this->_root;
				this->_root = tmp_root;
				
				node_pointer tmp_begin = x._begin;
				x._begin = this->_begin;
				this->_begin = tmp_begin;
				
				node_pointer tmp_end = x._end;
				x._end = this->_end;
				this->_end = tmp_end;

				size_type tmp_size = x._size;
				x._size = this->_size;
				this->_size = tmp_size;
			}

			void clear()
			{
			/* Removes all elements from the vector (which are destroyed), leaving the container with a size of 0. */
				if (this->empty())
					return;
				for (node_pointer it = _root; it != _end; it = _root) {
					this->erase(iterator(it)); }
				_end->parent = NULL;
				_root = _end;
				_begin = _end;
			}

		//--------------------------------------------------------------------//
		//                               OBSERVERS                            //
		//--------------------------------------------------------------------//

					// key_comp		OK
					// value_comp	OK

			key_compare key_comp() const
			{
			/* Returns a copy of the comparison object used by the container to compare keys. */
				return (this->_comp);
			}

			key_compare value_comp() const
			{
				return (Compare(this->_comp));
			}

		//--------------------------------------------------------------------//
		//                              OPERATIONS                            //
		//--------------------------------------------------------------------//

					// find								OK
					// count							OK
					// lower_bound (normal & const)		OK
					// upper_bound (normal & const)		OK
					// equal_range (normal & const)		OK

			node_pointer rec_find(node_pointer node, const key_type& k)
			{
				node_pointer	ret;

				if (node->pair.first == k) 
					return (node);
				else if (_comp(k, node->pair.first))
				{
					if (node->left && node->left != _end) {
						ret = rec_find(node->left, k);
						return (ret) ;
					}
					return (NULL);
				}
				else
				{
					if (node->right && node->right != _end) {
						ret = rec_find(node->right, k);
						return (ret) ;
					}
					return (NULL);
				}
			}

			node_pointer rec_find(node_pointer node, const key_type& k) const
			{
				node_pointer	ret;

				if (node->pair.first == k) 
					return (node);
				else if (_comp(k, node->pair))
				{
					if (node->left && node->left != _end) {
						ret = rec_find(node->left, k);
						return (ret) ;
					}
					return (NULL);
				}
				else
				{
					if (node->right && node->right != _end) {
						ret = rec_find(node->right, k);
						return (ret) ;
					}
					return (NULL);
				}
			}

			iterator find (const key_type& k)
			{
			/* Searches the container for an element with a key equivalent to k and returns
			an iterator to it if found, otherwise returns an iterator to map::end. */
				node_pointer ret = _root;
				if (this->empty())
					return (iterator(ret));
				ret = rec_find(ret, k);
				if (!ret)
					ret = _end;
				return (iterator(ret));
			}
			
			const_iterator find (const key_type& k) const
			{
				node_pointer ret = _root;
				if (this->empty())
					return (const_iterator(ret));
				ret = rec_find(ret, k);
				if (!ret)
					ret = _end;
				return (const_iterator(ret));
			}

			size_type count (const key_type& k) const
			{
				node_pointer ret = this->find(k).as_ptr();
				if (ret != _end)
					return (1);
				return (0);
			}

			iterator lower_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (!_comp(*it, k))
						return (it);
				return (this->end());
			}
			
			const_iterator lower_bound (const key_type& k) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (!_comp(*it, k))
						return (it);
				return (this->end());
			}

			iterator upper_bound (const key_type& k)
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					if (_comp(k, *it))
						return (it);
				return (this->end());
			}

			const_iterator upper_bound (const key_type& k) const
			{
				for (const_iterator it = this->begin(); it != this->end(); it++)
					if (_comp(k, *it))
						return (it);
				return (this->end());
			}

			pair<iterator,iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

		//--------------------------------------------------------------------//
		//                               ALLOCATOR                            //
		//--------------------------------------------------------------------//
		
					// get_allocator	OK

			allocator_type get_allocator() const
			{
				return(_alloc);
			}
	}; // fin de la class map

	//--------------------------------------------------------------------//
	//                        OVERLOAD OPERATOR                           //
	//--------------------------------------------------------------------//

	// Comparison operator ------------

	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator itr = rhs.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator itl = lhs.begin();
		while (itr != rhs.end())
		{
			if (*itr != *itl)
				return (false);
			++itl;
			++itr;
		}
		return (true);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (!(lhs == rhs))
			return (true);
		return (false);
	}
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator< ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
		// return (!(rhs < lhs) && !(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs > rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}

	// Swap ---------------------------

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}
}

# endif /* MAP_HPP */