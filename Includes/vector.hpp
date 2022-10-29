/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:09:51 by iderighe          #+#    #+#             */
/*   Updated: 2022/10/29 15:18:55 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

/* vector = tableau dynamique. Il alloue plus de memoire que nécessaire pour pouvoir
croître sans avoir besoin de free / reallouer ! */

# include <iostream>
# include <memory>
# include "iterator.hpp"
# include "random_access_iterator.hpp"

/* Namespace provides the scope where we can define or declare identifier. Avoid
name collision (ex : if 2 libraries have the same name for a fonction...) No
semi-colon after end of scope (unlike class)*/

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T															value_type;
			typedef	Allocator			 										allocator_type;
			typedef std::size_t													size_type;
			typedef std::ptrdiff_t												difference_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename ft::random_access_iterator<T>						iterator;
			typedef typename ft::random_access_iterator<const T>				const_iterator;
			// typedef typename ft::reverse_iterator<iterator>						reverse_iterator;
			// typedef typename ft::reverse_iterator<const iterator>				const_reverse_iterator;
			// typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;


			
		protected:
			allocator_type	_alloc;		// ALLOCATEUR !!
			// value_type		*_type;		// type des données qu'on met dans le vecteur (int, char...)
			size_type		_size;		// nb d'elements dans le vector 
			size_type		_capacity;	// nb d'elements possibles (en fct de la mémoire allouée)
			pointer			_array;
			
		public:
		
		//--------------------------------------------------------------------//
		//                                COPLIEN                             //
		//--------------------------------------------------------------------//

					// Constructors (4)
					// Destructor
					// operator=

		//------------------------- Constructeurs ----------------------------//
		/*Il y a quatre constructeurs:

		1) un contructeur par défaut (càd sans argument pour simplement créer le vecteur) 
		2) un constructeur avec 1er param = taille de base, 2eme param = valeur a mettre dans tout les cas (si elle est absente
		la valeur du constructeur par default sera utilisée
		3) un constructeur avec une plage d'iterateur a mettre a l'iterieur a l'initalisation
		4) un constructeur par copie

		ATTENTION : Le dernier argument de chaque constructeur est l'allocateur utiisé par le vecteur, 
		si rien n'est precisé un "allocator_type" sera instancié.*/
		
		// ----- 1) Default constructor. Constructs empty container ----- //
			explicit vector( const Allocator& alloc = Allocator() )
			{
				_alloc = alloc;
				// _type = 0;
				_size = 0;
				_capacity = 0;
				_array = NULL;
				std::cout << "Constructeur par défaut : \n_size = " << size() << "\n_capacity = " << capacity() << std::endl; 
			}
			
		// ----- 2) Constructs the container with count copies of elements with value value ----- //
			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() )
			{
				_alloc = alloc;
				_size = count;
				_capacity = count;
				_array = NULL;
				/* L'objet _alloc, de classe Allocator, va utiliser les fct de sa classe !
				1) allocate(std::size_type count, const void * hint = 0)
						|-> Allocates n * sizeof(T) bytes of uninitialized storage by calling ::operator new(std::size_t). So this function creates an array of type T[n] in the storage
				2) construct(void construct pointer p, const_reference val)
						|-> constructs an object of type T in allocated uninitialized storage pointed to by p*/
				if (count > 0)
				{
					this->_array = _alloc.allocate(count);
					for (size_type i = 0; i < count; i++)
						this->_alloc.construct(this->_array + i, value);
				}
				// _type = _alloc.allocate(count);
				// for (size_type i = 0; i < count; i++)
				// 	_alloc.construct(_type + i, value);
				std::cout << "Constructeur par param : \n_size = " << size() << "\n_capacity = " << capacity() << std::endl;
			}
			
		// ----- 3) Constructs the container with the contents of the range [first, last] ----- //
			template< class InputIterator >
			vector( InputIterator first, InputIterator last, const Allocator& alloc = Allocator() )
			{
				_alloc = alloc;
				_size = last - first;
				
				_capacity = _size;
				std::cout << "Constructeur par plage : \n_size = " << size() << "\n_capacity = " << capacity() << std::endl;
			}
			
		// ----- 4) Copy constructor. Constructs the container with the copy of the contents of other. If alloc is not provided, allocator is obtained by calling std::allocator_traits<allocator_type>::select_on_container_copy_construction(other). ----- //
			vector( const vector& other )
			{
				_alloc = other.get_allocator();
				_size = other.size();
				_capacity = other.capacity();
				_array = NULL;
				// _type = 0;
				if (other.size() > 0)
				{
					this->_array = this->_alloc.allocate(this->_capacity);
					for (size_type i = 0; i < other.size(); i++)
						this->_alloc.construct(this->_array + i, *(other._array + i));
				}
				std::cout << "Constructeur par copie : \n_size = " << size() << "\n_capacity = " << capacity() << std::endl;
			}
		
		//------------------------- Destructeur ----------------------------//
		/* Destructs the vector. The destructors of the elements are called and the used storage is deallocated. 
		Note that if the elements are pointers, the pointed-to objects are not destroyed. */
			virtual ~vector(void)
			{
				clear();
				if (this->_capacity > 0)
					this->_alloc.deallocate(this->_array, this->_capacity);
				std::cout << "Destructor Called \n-------------------------------------------------------------" << std::endl;
			}

		//-------------------------- Operateur = -----------------------------//
		/* Copy assignment operator. Replaces the contents with a copy of the contents of other. the allocator
		of *this is replaced by a copy of that of other. If the allocator of *this after assignment would compare
		unequal to its old value, the old allocator is used to deallocate the memory, then the new allocator
		is used to allocate it before copying the elements. Otherwise, the memory owned by *this may be reused
		when possible. In any case, the elements originally belonging to *this may be either destroyed
		or replaced by element-wise copy-assignment. */
			vector& operator=( const vector& other )
			{
				if (this != &other)
				{
					clear();
					assign(other.begin(), other.end());
				}
				return (*this);
			}

		//--------------------------------------------------------------------//
		//                              ITERATORS                             //
		//--------------------------------------------------------------------//

					// begin (normal & const)	OK
					// end (normal & const)		OK
					// rbegin
					// rend
					// cbegin					C11 !
					// cend						C11 !
					// crbegin					C11 !
					// crend					C11 !

			iterator begin()
			{
				return (iterator(this->_array));
			}

			const_iterator begin() const
			{
				return (const_iterator(this->_array));
			}
			
			iterator end()
			{
				return (iterator(this->_array + this->_size));
			}
			
			const_iterator end() const
			{
				return (const_iterator(this->_array + this->_size));
			}






		//--------------------------------------------------------------------//
		//                               CAPACITY                             //
		//--------------------------------------------------------------------//

					// size				OK
					// max_size			OK
					// resize			OK
					// capacity			OK
					// empty			OK
					// reserve			OK
					// shrink_to_fit	C11 !

			size_type size() const
			{
				return (this->_size);
			}

			size_type max_size() const
			{
				return (this->_alloc.max_size());
			}

			size_type reserve_calc(size_type n)
			{
				if (n <= _size * 2)
					return (_size * 2);
				return (n);
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n == size())
					return;
				if (n < size())
				{
				/* If n is smaller than the current container size, the content is reduced to its
				first n elements, removing those beyond (and destroying them). */
					for (size_type i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_array + i);
				}
				if (n > size())
				{
				/* If n is greater than the current container capacity, an automatic
				reallocation of the allocated storage space takes place. */
					if (n > capacity())
						reserve(reserve_calc(n));
				/* If n is greater than the current container size, the content is expanded by inserting
				at the end as many elements as needed to reach a size of n. If val is specified, the new
				elements are initialized as copies of val, otherwise, they are value-initialized. */
					for (size_type i = this->_size; i < n; i++)
						this->_alloc.construct(this->_array + i, val);
				}
				this->_size = n;
			}

			size_type capacity() const
			{
			/* Returns the size of the storage space currently allocated for the vector, expressed in terms of elements. */
				return (this->_capacity);
			}
		
			bool empty() const
			{
			/* Returns whether the vector is empty (i.e. whether its size is 0). */
				if (size())
					return (false);
				return (true);
			}

			void reserve (size_type n)
			{
			/* If the size requested is greater than the maximum size (vector::max_size), a length_error exception is thrown. */
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
			/* Requests that the vector capacity be at least enough to contain n elements. */
				if (n <= capacity())
					return;
			/* If n is greater than the current vector capacity, the function causes the container
			to reallocate its storage increasing its capacity to n (or greater).*/
				pointer	tmp_array = this->_alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					if (i < this->_size)
					{
						this->_alloc.construct(tmp_array + i, *(this->_array + i));
						this->_alloc.destroy(this->_array + i);
					}
				}
				if (this->_capacity != 0)
					this->_alloc.deallocate(_array, _capacity);
				this->_capacity = n;
				this->_array = tmp_array;
			}

		//--------------------------------------------------------------------//
		//                            ELEMENT ACCESS                          //
		//--------------------------------------------------------------------//

					// operator[] (2 fct : normal & const)	OK
					// at (2 fct : normal & const)			OK
					// front (2 fct : normal & const)		OK
					// back (2 fct : normal & const)		OK
					// data (C11)							C11 !

			reference operator[] (size_type n)
			{
			/* Returns a reference to the element at position n in the vector container. Does not check against bounds. */
				return (*(_array + n));
			}
			
			const_reference operator[] (size_type n) const
			{
				return (*(_array + n));
			}

			reference at (size_type n)
			{
			/* Returns a reference to the element at position n in the vector. The function automatically
			checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range
			exception if it is not (i.e., if n is greater than, or equal to, its size).
			This is in contrast with member operator[], that does not check against bounds.*/
				if (n >= _size)
					throw std::out_of_range("vector::at -> index out of range !");
				else
					return (*(_array + n));	
			}
			
			const_reference at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("vector::at -> index out of range !");
				else
					return (*(_array + n));	
			}

			reference front()
			{
			/* Returns a reference to the first element in the vector. Unlike member vector::begin, which
			returns an iterator to this same element, this function returns a direct reference. */
				return *(this->begin());
			}
			
			const_reference front() const
			{
				return *(this->begin());
			}

			reference back()
			{
			/* Returns a reference to the last element in the vector. Unlike member vector::end, which
			returns an iterator just past this element, this function returns a direct reference. */
				size_type pos = this->_size - 1;
				if (pos < 0)
					pos = 0;
				return (*(_array + pos));
			}
			
			const_reference back() const
			{
				size_type pos = this->_size - 1;
				if (pos < 0)
					pos = 0;
				return (*(_array + pos));
			}

		//--------------------------------------------------------------------//
		//                               MODIFIERS                            //
		//--------------------------------------------------------------------//

					// assign (2 fct : fill & range !)			OK
					// push_back								OK
					// pop_back									OK
					// insert (3 fct : single & fill & range)
					// erase (2 fct : single & range)
					// swap
					// clear
					// emplace									C11 !
					// emplace_back								C11 !

			void	assign(size_t n, const value_type &val)
			{
			/* prototype assign |-> fill : the new contents are n elements, each initialized to a copy of val.
			Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.*/
				clear();
				if (n == 0)
					return;
				this->_size = n;
				if (this->_capacity < n)
				{
					this->_alloc.deallocate(this->_array, this->_capacity);
					this->_capacity = n;
					this->_array = this->_alloc.allocate(this->_capacity);
				}
				for (size_type i = 0; i < n; i++)
					this->_alloc.construct(this->_array + i, val);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
			/* prototype assign |-> range : the new contents are elements constructed from each of the elements in the
			range between first and last, in the same order.
			Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.*/
				clear();
				insert(begin(), first, last);
			}


			void push_back (const value_type& val)
			{
				if (this->_capacity == 0)
					this->reserve(1);
				else if (_capacity <= _size)
					this->reserve(reserve_calc(this->_size + 1));
				this->_alloc.construct(this->_array + this->_size, val);
				this->_size++;
			}

			void pop_back()
			{
				if (this->_size > 0)
				{
					this->_size--;
					this->_alloc.destroy(this->_array + this->_size);
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
			/* The vector is extended by inserting new elements before the element at the specified position,
			effectively increasing the container size by the number of elements inserted.
			This causes an automatic reallocation of the allocated storage space if -and only if- the new vector
			size surpasses the current vector capacity. */
			
			/* insert one element of value val in position position */
				
				difference_type diff = position - begin();
				if (this->_size + 1 > this->_capacity)
					reserve(reserve_calc(this->_size + 1));
				pointer index = _array + _size;
				pointer stop = _array + diff;
				
			/* on remplit par la fin ! */
				for(; index != stop; index--)
				{
					this->_alloc.construct(index, *(index - 1));
					this->_alloc.destroy(index - 1);
				}
			/* on insère l'element en position */
				this->_alloc.construct(stop, val);
				_size++;
				return (begin() + diff);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n > capacity())
					reserve(reserve_calc(n));
				difference_type diff = position - begin();
				pointer index = _array + _size + n;
				pointer stop = _array + diff + n;

			/* on remplit par la fin ! */
				for (; index != stop; index--)
				{
					this->_alloc.construct(index, *(index - 1));
					this->_alloc.destroy(index - 1);
				}
			/* on insère les elements en position */
				for (size_type i = diff; i < n; i++)
					this->_alloc.construct(i, val);
				_size = _size + n;
				return (begin() + diff);
			}

			// template <class InputIterator>
			// void insert (iterator position, InputIterator first, InputIterator last)
			// {
				
			// }

			iterator erase (iterator position)
			{
			/* Removes from the vector a single element. This effectively reduces the container
			size by the number of elements removed, which are destroyed.*/
				if (empty())
					return (end());
				iterator cursor = position;
				iterator ite = this->end();

				for (; (cursor + 1) != ite; cursor++)
					cursor[0] = cursor[1];
				this->_alloc.destroy(this->_array + this->_size - 1);
				this->_size--;
				return (position);
			}

			// iterator erase (iterator first, iterator last)
			// {
			// 	for (first; first != last; last--)
			// 		erase(first);
			// 	return (first);
			// }



void swap (vector& x);



			void clear()
			{
			/* Removes all elements from the vector (which are destroyed), leaving the container with a size of 0. */
				if (this->_size == 0)
					return;
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_array + i);
				this->_size = 0;
			}
			
// template <class... Args>iterator emplace (const_iterator position, Args&&... args);	

// template <class... Args>  void emplace_back (Args&&... args);

		//--------------------------------------------------------------------//
		//                               ALLOCATOR                            //
		//--------------------------------------------------------------------//
		
					// get_allocator

			allocator_type get_allocator() const
			{
				return(_alloc);
			}
	};
}

#endif /* VECTOR_HPP */