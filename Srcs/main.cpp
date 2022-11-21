/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:08:12 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/21 12:16:51 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include "vector.hpp"

// #define RESET "\e[0m"
// #define RED "\e[0;31m"
// #define GREEN "\e[0;32m"
// #define YELLOW "\e[0;33m"
// #define BLUE "\e[0;34m"
// #define PURPLE "\e[0;35m"
// #define CYAN "\e[0;36m"
// #define ORANGE "\e[38;2;255;165;0m"

// # ------ GRIS ------ #
#define GRAY "\033[90m" 
#define REALGRAY "\033[38;2;128;128;128m"
#define SILVER "\033[38;2;192;192;192m"
#define LIGHTSLATEGRAY "\033[38;2;119;136;153m"
// # ------ ROUGE ------ #
#define RED "\033[91m" 
#define ORANGE "\033[38;2;255;165;0m"
#define FIREBRICK "\033[38;2;178;34;34m"
#define INDIANRED "\033[38;2;205;92;92m"
//  # ------ VERT ------ #
#define GREEN "\033[92m"
#define LIMEGREEN "\033[38;2;50;205;50m"
#define FORESTGREEN "\033[38;2;34;139;34m"
#define SPRINGGREEN "\033[38;2;0;255;127m"
// # ------ JAUNE ------ #
#define YELLOW "\033[93m" 
#define KHAKI "\033[38;2;240;230;140m"
#define REALYELLOW "\033[38;2;255;255;0m"
#define GOLD "\033[38;2;255;215;0m"
// # ------ BLEU ------ #
#define BLUE "\033[94m" 
#define REALBLUE "\033[38;2;0;0;255m"
#define DEEPSKYBLUE "\033[38;2;0;191;255m"
#define ROYALBLUE "\033[38;2;65;105;225m"
// # ------ VIOLET ------ #
#define PURPLE "\033[95m" 
#define FUCHSIA "\033[38;2;255;0;255m"
#define DARKVIOLET "\033[38;2;148;0;211m"
#define DARKMAGENTA "\033[38;2;139;0;139m"
// # ------ CYAN ------ #
#define CYAN "\033[96m" 
#define AQUAMARINE "\033[38;2;127;255;212m"
#define PALETURQUOISE "\033[38;2;175;238;238m"
#define TEAL "\033[38;2;0;128;128m"
//# ------ RESET ------ #
#define RESET "\033[0m"


template <class vector1, class vector2>
void	print_status(vector1 &ft_vect, vector2 &std_vect)
{
	std::cout << FUCHSIA << "\t\t    | ---- my vector (ft) ---- | ---- vector standard ---- |" << RESET << std::endl;
	std::cout << SILVER << "- size =\t\t" << ft_vect.size() << std::setw(27) << std_vect.size() << "\n- capacity =\t\t" << ft_vect.capacity()
	<< std::setw(27) << std_vect.capacity() << "\n- max_size =\t\t" << ft_vect.max_size() << std::setw(27) << std_vect.max_size() << "\n- containter empty ?\t"
	<< std::boolalpha << ft_vect.empty() <<  std::setw(27) << std_vect.empty() << std::endl;
	for (int i = 0; i < (int)ft_vect.size(); i++)
			std::cout << "\tcontent[" << i << "]\t" << ft_vect[i] << std::setw(27) << std_vect[i] << std::endl;
	std::cout << RESET << std::endl;
}


int	main()
{
	// if (argc != 2)
	// {
	// 	std::cerr << "Usage: ./test seed" << std::endl;
	// 	std::cerr << "Provide a seed please" << std::endl;
	// 	// std::cerr << "Count value:" << COUNT << std::endl;
	// 	return 1;
	// }
	// argv = NULL;

	{
		std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << RED << "-------------------------- TEST DES CONSTRUCTEURS --------------------------" << RESET << std::endl;
		std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "Test Constructeur 1 : default constructor !" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "vector d'int ---------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<int> first;
		std::vector<int> vct;
		print_status(first, vct);

		std::cout << "testons une fonction : push_back (on entre la valeur 7)" << std::endl;
		first.push_back(7);
		vct.push_back(7);
		print_status(first, vct);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<char> second;
		std::vector<char> vct_char;
		print_status(second, vct_char);

		std::cout << "testons une fonction : push_back (on entre la valeur 'a')" << std::endl;
		second.push_back('a');
		vct_char.push_back('a');
		print_status(second, vct_char);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<std::string> third;
		std::vector<std::string> vct_str;
		print_status(third, vct_str);

		std::cout << "testons une fonction : push_back (on entre la valeur 'Salut !')" << std::endl;
		third.push_back("Salut !");
		vct_str.push_back("Salut !!!!!");
		print_status(third, vct_str);

		std::cout << YELLOW << "vector de float ------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<float> fourth;
		std::vector<float> vct_float;
		print_status(fourth, vct_float);

		std::cout << "testons une fonction : push_back (on entre la valeur '42.4221 !')" << std::endl;
		fourth.push_back(42.4221);
		vct_float.push_back(42.4221);
		print_status(fourth, vct_float);
	}

	{
		// std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
		// std::cout << RED << "-------------------------- TEST DES CONSTRUCTEURS --------------------------" << RESET << std::endl;
		// std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "Test Constructeur 2 : param constructor (n elem of value val) !" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "vector d'int ---------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<int> first(5, 8);
		std::vector<int> vct(5, 8);
		print_status(first, vct);

		std::cout << "testons une fonction : push_back (on entre la valeur 7)" << std::endl;
		first.push_back(7);
		vct.push_back(7);
		print_status(first, vct);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<char> second(3, 'b');
		std::vector<char> vct_char(3, 'b');
		print_status(second, vct_char);

		std::cout << "testons une fonction : push_back (on entre la valeur 'a')" << std::endl;
		second.push_back('a');
		vct_char.push_back('a');
		print_status(second, vct_char);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<std::string> third(2, "Hello...");
		std::vector<std::string> vct_str(2, "Hello !");
		print_status(third, vct_str);

		std::cout << "testons une fonction : push_back (on entre la valeur 'Salut !')" << std::endl;
		third.push_back("Salut !");
		vct_str.push_back("Salut !!!!!");
		print_status(third, vct_str);

		std::cout << YELLOW << "vector de float ------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<float> fourth(4, 21.2121);
		std::vector<float> vct_float(4, 21.2121);
		print_status(fourth, vct_float);

		std::cout << "testons une fonction : push_back (on entre la valeur '42.4221 !')" << std::endl;
		fourth.push_back(42.4242);
		vct_float.push_back(42.4242);
		print_status(fourth, vct_float);
	}

	{
		// std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
		// std::cout << RED << "-------------------------- TEST DES CONSTRUCTEURS --------------------------" << RESET << std::endl;
		// std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "Test Constructeur 3 : range constructor (fill with a range (first, last) !" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "vector d'int ---------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<int> first;
		first.push_back(42);
		first.push_back(53);
		first.push_back(-12);
		first.push_back(21);
		first.push_back(-2);
		first.push_back(66);

		std::vector<int> vct;
		vct.push_back(42);
		vct.push_back(53);
		vct.push_back(-12);
		vct.push_back(21);
		vct.push_back(-2);
		vct.push_back(66);

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(first, vct);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		ft::vector<int>::iterator itf_ft_begin = first.begin() + 1;
		ft::vector<int>::iterator itf_ft_end = first.begin() + 4;
		std::vector<int>::iterator itvi_std_begin = vct.begin() + 1;
		std::vector<int>::iterator itvi_std_end = vct.begin() + 4;

		ft::vector<int> first_range(itf_ft_begin, itf_ft_end);
		std::vector<int> vct_range(itvi_std_begin, itvi_std_end);
		print_status(first, vct);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<char> second;
		second.push_back('a');
		second.push_back('b');
		second.push_back('c');
		second.push_back('d');
		second.push_back('e');
		second.push_back('f');

		std::vector<char> vct_char;
		vct_char.push_back('a');
		vct_char.push_back('b');
		vct_char.push_back('c');
		vct_char.push_back('d');
		vct_char.push_back('e');
		vct_char.push_back('f');

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(second, vct_char);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		ft::vector<char>::iterator its_ft_begin = second.begin() + 1;
		ft::vector<char>::iterator its_ft_end = second.begin() + 4;
		std::vector<char>::iterator itvc_std_begin = vct_char.begin() + 1;
		std::vector<char>::iterator itvc_std_end = vct_char.begin() + 4;

		ft::vector<char> second_range(its_ft_begin, its_ft_end);
		std::vector<char> vct_char_range(itvc_std_begin, itvc_std_end);
		print_status(second, vct_char);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<std::string> third;
		third.push_back("Salut");
		third.push_back("Bonjour");
		third.push_back("Ciao");
		third.push_back("Hello");
		third.push_back("Guten tag");
		third.push_back("Grumph");

		std::vector<std::string> vct_str;
		vct_str.push_back("Salut");
		vct_str.push_back("Bonjour");
		vct_str.push_back("Ciao");
		vct_str.push_back("Hello");
		vct_str.push_back("Guten tag");
		vct_str.push_back("Grumph");

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(third, vct_str);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		ft::vector<std::string>::iterator itt_ft_begin = third.begin() + 1;
		ft::vector<std::string>::iterator itt_ft_end = third.begin() + 4;
		std::vector<std::string>::iterator itvs_std_begin = vct_str.begin() + 1;
		std::vector<std::string>::iterator itvs_std_end = vct_str.begin() + 4;

		ft::vector<std::string> third_range(itt_ft_begin, itt_ft_end);
		std::vector<std::string> vct_str_range(itvs_std_begin, itvs_std_end);
		print_status(third, vct_str);

		std::cout << YELLOW << "vector de float ------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<float> fourth;
		fourth.push_back(42.123);
		fourth.push_back(53.456);
		fourth.push_back(-12.789);
		fourth.push_back(21.741);
		fourth.push_back(-2.852);
		fourth.push_back(66.963);

		std::vector<float> vct_float;
		vct_float.push_back(42.123);
		vct_float.push_back(53.456);
		vct_float.push_back(-12.789);
		vct_float.push_back(21.741);
		vct_float.push_back(-2.852);
		vct_float.push_back(66.963);

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(fourth, vct_float);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		ft::vector<float>::iterator itfo_ft_begin = fourth.begin() + 1;
		ft::vector<float>::iterator itfo_ft_end = fourth.begin() + 4;
		std::vector<float>::iterator itvf_std_begin = vct_float.begin() + 1;
		std::vector<float>::iterator itvf_std_end = vct_float.begin() + 4;

		ft::vector<float> fourth_range(itfo_ft_begin, itfo_ft_end);
		std::vector<float> vct_float_range(itvf_std_begin, itvf_std_end);
		print_status(fourth, vct_float);
	}

	{
		// std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
		// std::cout << RED << "-------------------------- TEST DES CONSTRUCTEURS --------------------------" << RESET << std::endl;
		// std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "Test Constructeur 4 : copy constructor !" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "vector d'int ---------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<int> first(5, 8);
		std::vector<int> vct(5, 8);

		std::cout << PALETURQUOISE << "\n2 types d'appel au copy constructor : vector<> vct_cpy = vct et vector<> vct_cpy(vct)" << RESET << std::endl;

		ft::vector<int> f_cpy_equal = first;
		std::vector<int> vi_cpy_equal = vct;

		f_cpy_equal.push_back(7);
		vi_cpy_equal.push_back(7);

		ft::vector<int> f_cpy_param(f_cpy_equal);
		std::vector<int> vi_cpy_param(vi_cpy_equal);

		f_cpy_param.push_back(5);
		vi_cpy_param.push_back(5);

		std::cout << "testons une fonction : push_back (on entre la valeur 7 dans les copies equal et 5 dans les copies param des copies equal!)" << std::endl;
		std::cout << SILVER << "vectors originaux : " << std::endl; 
		print_status(first, vct);
		std::cout << SILVER << "vectors copy equal : " << std::endl; 
		print_status(f_cpy_equal, vi_cpy_equal);
		std::cout << SILVER << "vectors copy param : " << std::endl; 
		print_status(f_cpy_param, vi_cpy_param);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<char> second(3, 'b');
		std::vector<char> vct_char(3, 'b');

		std::cout << PALETURQUOISE << "\n2 types d'appel au copy constructor : vector<> vct_cpy = vct et vector<> vct_cpy(vct)" << RESET << std::endl;

		ft::vector<char> s_cpy_equal = second;
		std::vector<char> vc_cpy_equal = vct_char;

		s_cpy_equal.push_back('i');
		vc_cpy_equal.push_back('i');

		ft::vector<char> s_cpy_param(s_cpy_equal);
		std::vector<char> vc_cpy_param(vc_cpy_equal);

		s_cpy_param.push_back('j');
		vc_cpy_param.push_back('j');

		std::cout << "testons une fonction : push_back (on entre la valeur 'i' dans les copies equal et 'j' dans les copies param des copies equal!)" << std::endl;
		std::cout << SILVER << "vectors originaux : " << std::endl; 
		print_status(second, vct_char);
		std::cout << SILVER << "vectors copy equal : " << std::endl; 
		print_status(s_cpy_equal, vc_cpy_equal);
		std::cout << SILVER << "vectors copy param : " << std::endl; 
		print_status(s_cpy_param, vc_cpy_param);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		ft::vector<std::string> third;
		third.push_back("Salut");
		third.push_back("Bonjour");
		third.push_back("Ciao");
		third.push_back("Hello");
		third.push_back("Guten tag");

		std::vector<std::string> vct_str;
		vct_str.push_back("Salut");
		vct_str.push_back("Bonjour");
		vct_str.push_back("Ciao");
		vct_str.push_back("Hello");
		vct_str.push_back("Guten tag");

		try
		{
			std::cout << third.at(7) << std::endl;
			std::cout << vct_str.at(7) << std::endl;
		}
		catch(std::exception &e){std::cout <<  e.what() << std::endl;}

		std::cout << PALETURQUOISE << "\n2 types d'appel au copy constructor : vector<> vct_cpy = vct et vector<> vct_cpy(vct)" << RESET << std::endl;

		ft::vector<std::string> t_cpy_equal = third;
		std::vector<std::string> vs_cpy_equal = vct_str;

		t_cpy_equal.push_back("blablabla");
		vs_cpy_equal.push_back("blablabla");

		ft::vector<std::string> t_cpy_param(t_cpy_equal);
		std::vector<std::string> vs_cpy_param(vs_cpy_equal);

		t_cpy_param.push_back("Grumph");
		vs_cpy_param.push_back("Grumph");

		std::cout << "testons une fonction : push_back (on entre la valeur 'i' dans les copies equal et 'j' dans les copies param des copies equal!)" << std::endl;
		std::cout << SILVER << "vectors originaux : " << std::endl; 
		print_status(third, vct_str);
		std::cout << SILVER << "vectors copy equal : " << std::endl; 
		print_status(t_cpy_equal, vs_cpy_equal);
		std::cout << SILVER << "vectors copy param : " << std::endl; 
		print_status(t_cpy_param, vs_cpy_param);
	}





	{
		std::cout << std::endl << std::endl;
		std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << RED << "---------------------------- TEST DES FONCTIONS ----------------------------" << RESET << std::endl;
		std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "		Test vector d'int" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur vector vide (constructeur par défaut)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "situation initiale : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			first.assign(4, 21);
			vct.assign(4, 21);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;

			ft::vector<int> second(7, 13);
			std::vector<int> vct_scd(7, 13);

			ft::vector<int>::iterator begin = second.begin() + 1;
			ft::vector<int>::iterator end = second.begin() + 4;
			std::vector<int>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<int>::iterator std_end = vct_scd.begin() + 4;
			first.assign(begin, end);
			vct.assign(std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			first.push_back(42);
			vct.push_back(42);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : sur container vide -> undefined behavior" << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			first.pop_back();
			vct.pop_back();
			print_status(first, vct);
			// try
			// 	{std::cout << first[5] << std::endl;}
			// catch (std::exception &e)
			// 	{std::cout << e.what() << std::endl;}
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			ft::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator vct_insert = vct.begin();
			first.insert(itinsert, 27);
			vct.insert( vct_insert, 27);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			ft::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator vct_insert = vct.begin();
			first.insert(itinsert, 4, 42);
			vct.insert(vct_insert, 4, 42);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;

			ft::vector<int> second(7, 13);
			std::vector<int> vct_scd(7, 13);
			
			ft::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator vct_insert = vct.begin();
			
			ft::vector<int>::iterator begin = second.begin() + 1;
			ft::vector<int>::iterator end = second.begin() + 4;
			std::vector<int>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<int>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			std::cout << INDIANRED << "ATTENTION : erase sur un vector standard vide = crash !" << RESET << std::endl;
			ft::vector<int>::iterator iterase = first.begin();
			// std::vector<int>::iterator vct_erase = vct.begin();
			first.erase(iterase);
			// vct.erase(vct_erase);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			ft::vector<int>::iterator iterase_first = first.begin();
			ft::vector<int>::iterator iterase_last = first.end();
			std::vector<int>::iterator vct_erase_begin = vct.begin();
			std::vector<int>::iterator vct_erase_end = vct.end();
			first.erase(iterase_first, iterase_last);
			vct.erase(vct_erase_begin, vct_erase_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<int> first;
			ft::vector<int> second;
			std::vector<int> vct;
			std::vector<int> vct2;
			print_status(first, vct);
			print_status(second, vct2);
			first.swap(second);
			vct.swap(vct2);
			print_status(first, vct);
			print_status(second, vct2);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<int> first;
			std::vector<int> vct;
			first.clear();
			vct.clear();
			print_status(first, vct);
		}


		std::cout << std::endl << std::endl; 
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur vector initialisé (constructeur par param)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "situation initiale : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			first.assign(4, 21);
			vct.assign(4, 21);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);

			ft::vector<int> second(7, 13);
			std::vector<int> vct_scd(7, 13);
			print_status(first, vct);
			print_status(second, vct_scd);

			ft::vector<int>::iterator begin = second.begin() + 1;
			ft::vector<int>::iterator end = second.begin() + 4;
			std::vector<int>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<int>::iterator std_end = vct_scd.begin() + 4;
			first.assign(begin, end);
			vct.assign(std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			first.push_back(42);
			vct.push_back(42);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			first.pop_back();
			vct.pop_back();
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator vct_insert = vct.begin();
			first.insert(itinsert, 27);
			vct.insert( vct_insert, 27);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator itinsert = first.begin() + 2;
			std::vector<int>::iterator vct_insert = vct.begin() + 2;
			first.insert(itinsert, 27);
			vct.insert( vct_insert, 27);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator itinsert = first.end();
			std::vector<int>::iterator vct_insert = vct.end();
			first.insert(itinsert, 27);
			vct.insert( vct_insert, 27);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator vct_insert = vct.begin();
			first.insert(itinsert, 4, 42);
			vct.insert(vct_insert, 4, 42);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator itinsert = first.begin() + 3;
			std::vector<int>::iterator vct_insert = vct.begin() + 3;
			first.insert(itinsert, 4, 42);
			vct.insert(vct_insert, 4, 42);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator itinsert = first.end();
			std::vector<int>::iterator vct_insert = vct.end();
			first.insert(itinsert, 4, 42);
			vct.insert(vct_insert, 4, 42);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);

			ft::vector<int> second(7, 13);
			std::vector<int> vct_scd(7, 13);
			print_status(first, vct);
			print_status(second, vct_scd);

			ft::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator vct_insert = vct.begin();
			
			ft::vector<int>::iterator begin = second.begin() + 1;
			ft::vector<int>::iterator end = second.begin() + 4;
			std::vector<int>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<int>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);

			ft::vector<int> second(7, 13);
			std::vector<int> vct_scd(7, 13);
			
			ft::vector<int>::iterator itinsert = first.begin() + 3;
			std::vector<int>::iterator vct_insert = vct.begin() + 3;
			
			ft::vector<int>::iterator begin = second.begin() + 1;
			ft::vector<int>::iterator end = second.begin() + 4;
			std::vector<int>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<int>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);

			ft::vector<int> second(7, 13);
			std::vector<int> vct_scd(7, 13);
			
			ft::vector<int>::iterator itinsert = first.end();
			std::vector<int>::iterator vct_insert = vct.end();
			
			ft::vector<int>::iterator begin = second.begin() + 1;
			ft::vector<int>::iterator end = second.begin() + 4;
			std::vector<int>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<int>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator iterase = first.begin();
			std::vector<int>::iterator vct_erase = vct.begin();
			first.erase(iterase);
			vct.erase(vct_erase);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			ft::vector<int>::iterator iterase_first = first.begin();
			ft::vector<int>::iterator iterase_last = first.begin() + 2;
			std::vector<int>::iterator vct_erase_begin = vct.begin();
			std::vector<int>::iterator vct_erase_end = vct.begin() + 2;
			first.erase(iterase_first, iterase_last);
			vct.erase(vct_erase_begin, vct_erase_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			ft::vector<int> second(3, 13);
			std::vector<int> vct(5, 8);
			std::vector<int> vct2(3, 13);
			first.swap(second);
			vct.swap(vct2);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : " << RESET << std::endl;
			ft::vector<int> first(5, 8);
			std::vector<int> vct(5, 8);
			first.clear();
			vct.clear();
			print_status(first, vct);
		}





		std::cout << std::endl << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "		Test vector de string" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur vector vide (constructeur par défaut)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "situation initiale : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			first.assign(4, "salut !");
			vct.assign(4, "salut !");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;

			ft::vector<std::string> second(7, "Hello");
			std::vector<std::string> vct_scd(7, "Hello");
			print_status(first, vct);
			print_status(second, vct_scd);

			ft::vector<std::string>::iterator begin = second.begin() + 1;
			ft::vector<std::string>::iterator end = second.begin() + 4;
			std::vector<std::string>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<std::string>::iterator std_end = vct_scd.begin() + 4;
			first.assign(begin, end);
			vct.assign(std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			first.push_back("Coucou !");
			vct.push_back("Coucou !");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			std::cout << INDIANRED << "ATTENTION : pop_back sur un vector standard de string vide = crash !" << RESET << std::endl;
			first.pop_back();
			// vct.pop_back();
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			ft::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator vct_insert = vct.begin();
			first.insert(itinsert, "Hello World");
			vct.insert( vct_insert, "Hello World");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			ft::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator vct_insert = vct.begin();
			first.insert(itinsert, 4, "Grumph");
			vct.insert(vct_insert, 4, "Grumph");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;

			ft::vector<std::string> second(7, "Salut !");
			std::vector<std::string> vct_scd(7, "Salut !");
			print_status(first, vct);
			print_status(second, vct_scd);

			ft::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator vct_insert = vct.begin();
			
			ft::vector<std::string>::iterator begin = second.begin() + 1;
			ft::vector<std::string>::iterator end = second.begin() + 4;
			std::vector<std::string>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<std::string>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			std::cout << INDIANRED << "ATTENTION : erase sur un vector standard vide = crash !" << RESET << std::endl;
			ft::vector<std::string>::iterator iterase = first.begin();
			// std::vector<std::string>::iterator vct_erase = vct.begin();
			first.erase(iterase);
			// vct.erase(vct_erase);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			ft::vector<std::string>::iterator iterase_first = first.begin();
			ft::vector<std::string>::iterator iterase_last = first.end();
			std::vector<std::string>::iterator vct_erase_begin = vct.begin();
			std::vector<std::string>::iterator vct_erase_end = vct.end();
			first.erase(iterase_first, iterase_last);
			vct.erase(vct_erase_begin, vct_erase_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<std::string> first;
			ft::vector<std::string> second;
			std::vector<std::string> vct;
			std::vector<std::string> vct2;
			first.swap(second);
			vct.swap(vct2);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			ft::vector<std::string> first;
			std::vector<std::string> vct;
			first.clear();
			vct.clear();
			print_status(first, vct);
		}


		std::cout << std::endl << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur vector initialisé (constructeur par param)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "situation initiale : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			print_status(first, vct);
			first.assign(4, "Guten tag.");
			vct.assign(4, "Guten tag.");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");

			ft::vector<std::string> second(7, "Hello");
			std::vector<std::string> vct_scd(7, "Hello");
			print_status(first, vct);
			print_status(second, vct_scd);

			ft::vector<std::string>::iterator begin = second.begin() + 1;
			ft::vector<std::string>::iterator end = second.begin() + 4;
			std::vector<std::string>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<std::string>::iterator std_end = vct_scd.begin() + 4;
			first.assign(begin, end);
			vct.assign(std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			first.push_back("Coucou !");
			vct.push_back("Coucou !");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			first.pop_back();
			vct.pop_back();
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			print_status(first, vct);
			ft::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator vct_insert = vct.begin();
			first.insert(itinsert, "Hello World");
			vct.insert( vct_insert, "Hello World");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator itinsert = first.begin() + 3;
			std::vector<std::string>::iterator vct_insert = vct.begin() + 3;
			first.insert(itinsert, "Hello World");
			vct.insert( vct_insert, "Hello World");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator itinsert = first.end();
			std::vector<std::string>::iterator vct_insert = vct.end();
			first.insert(itinsert, "Hello World");
			vct.insert( vct_insert, "Hello World");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator vct_insert = vct.begin();
			first.insert(itinsert, 4, "Grumph");
			vct.insert(vct_insert, 4, "Grumph");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator itinsert = first.begin() + 2;
			std::vector<std::string>::iterator vct_insert = vct.begin() + 2;
			first.insert(itinsert, 4, "Grumph");
			vct.insert(vct_insert, 4, "Grumph");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator itinsert = first.end();
			std::vector<std::string>::iterator vct_insert = vct.end();
			first.insert(itinsert, 4, "Grumph");
			vct.insert(vct_insert, 4, "Grumph");
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");

			ft::vector<std::string> second(7, "Grumph");
			std::vector<std::string> vct_scd(7, "Grumph");
			
			ft::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator vct_insert = vct.begin();
			
			ft::vector<std::string>::iterator begin = second.begin() + 1;
			ft::vector<std::string>::iterator end = second.begin() + 4;
			std::vector<std::string>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<std::string>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");

			ft::vector<std::string> second(7, "Grumph");
			std::vector<std::string> vct_scd(7, "Grumph");
			
			ft::vector<std::string>::iterator itinsert = first.begin() + 3;
			std::vector<std::string>::iterator vct_insert = vct.begin() + 3;
			
			ft::vector<std::string>::iterator begin = second.begin() + 1;
			ft::vector<std::string>::iterator end = second.begin() + 4;
			std::vector<std::string>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<std::string>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");

			ft::vector<std::string> second(7, "Grumph");
			std::vector<std::string> vct_scd(7, "Grumph");
			
			ft::vector<std::string>::iterator itinsert = first.end();
			std::vector<std::string>::iterator vct_insert = vct.end();
			
			ft::vector<std::string>::iterator begin = second.begin() + 1;
			ft::vector<std::string>::iterator end = second.begin() + 4;
			std::vector<std::string>::iterator std_begin = vct_scd.begin() + 1;
			std::vector<std::string>::iterator std_end = vct_scd.begin() + 4;
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator iterase = first.begin();
			std::vector<std::string>::iterator vct_erase = vct.begin();
			first.erase(iterase);
			vct.erase(vct_erase);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			ft::vector<std::string>::iterator iterase_first = first.begin() + 2;
			ft::vector<std::string>::iterator iterase_last = first.end();
			std::vector<std::string>::iterator vct_erase_begin = vct.begin() + 2;
			std::vector<std::string>::iterator vct_erase_end = vct.end();
			first.erase(iterase_first, iterase_last);
			vct.erase(vct_erase_begin, vct_erase_end);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			ft::vector<std::string> second(3, "Hello...");
			std::vector<std::string> vct(5, "Salut !");
			std::vector<std::string> vct2(3, "Hello...");
			first.swap(second);
			vct.swap(vct2);
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : " << RESET << std::endl;
			ft::vector<std::string> first(5, "Salut !");
			std::vector<std::string> vct(5, "Salut !");
			first.clear();
			vct.clear();
			print_status(first, vct);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			ft::vector<std::string> first;
			first.push_back("Salut !");
			first.push_back("Guten Tag.");
			first.push_back("Glebeskefe");
			first.push_back("Hello World :D");
			first.push_back("Ciao");
			std::vector<std::string> vct;
			vct.push_back("Salut !");
			vct.push_back("Guten Tag.");
			vct.push_back("Glebeskefe");
			vct.push_back("Hello World :D");
			vct.push_back("Ciao");

			ft::vector<std::string> second;
			second.push_back("Baba");
			second.push_back("Bebe");
			second.push_back("Bibi");
			second.push_back("Bobo");
			second.push_back("Bubu");
			std::vector<std::string> vct_scd;
			vct_scd.push_back("Baba");
			vct_scd.push_back("Bebe");
			vct_scd.push_back("Bibi");
			vct_scd.push_back("Bobo");
			vct_scd.push_back("Bubu");
			print_status(first, vct);
			print_status(second, vct_scd);

			ft::vector<std::string>::iterator itinsert = first.begin() + 2;
			std::vector<std::string>::iterator vct_insert = vct.begin() + 2;
			
			ft::vector<std::string>::reverse_iterator begin = second.rbegin();
			ft::vector<std::string>::reverse_iterator end = second.rend();
			std::vector<std::string>::reverse_iterator std_begin = vct_scd.rbegin();
			std::vector<std::string>::reverse_iterator std_end = vct_scd.rend();
			
			first.insert(itinsert, begin, end);
			vct.insert(vct_insert, std_begin, std_end);
			print_status(first, vct);
		}


		// std::cout << SILVER << "- size =		" << fourth_range.size() << "			" << vct_float_range.size() << "\n- capacity =		" << fourth_range.capacity()
		// << "			" << vct_float_range.capacity() << "\n- containter empty ?	" << std::boolalpha << fourth_range.empty() << "			" << vct_float_range.empty() <<  std::endl;
		// for (int i = 0; i < (int)fourth_range.size(); i++)
		// 	std::cout << "	content[" << i << "]	" << fourth_range[i] << "			" << vct_float_range[i] << std::endl;
		// std::cout << RESET << std::endl;

		// ft::vector<int> first(5, 8);
		// std::vector<int> vct(5, 8);
		// std::cout << RED << "Test Constructeur 1 : empty vector of ints (default constructor !)" << RESET << std::endl;
		// ft::vector<int> first;
		
		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		
		// std::cout << std::endl << ORANGE << "Test des fonctions du container vector : " << RESET << std::endl;

		// --------------- PUSH_BACK --------------- //		
		// std::cout << YELLOW << "push_back : " << RESET << std::endl;
		// first.push_back(7);
		// // first.push_back(18);
		// // first.push_back(-5);
		// // first.push_back(-16);

		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;
		
		// // --------------- POP_BACK --------------- //
		// std::cout << YELLOW << "pop_back : " << RESET << std::endl;
		// first.pop_back();

		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;

		// // --------------- INSERT ONE ELEM  --------------- // A GARDER POUR LES TESTS SUR CONTAINERS AUTRES QUE DEFAULT !!
		// std::cout << YELLOW << "insert one elem : " << RESET << std::endl;
		// std::cout << SILVER << "résumé (container au départ) : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;

		// std::cout << AQUAMARINE << "insert one elem at position it (au début) (2 times)" << RESET << std::endl;
		// ft::vector<int>::iterator itinsert = first.begin();
		// first.insert(itinsert, 27);
		// first.insert(itinsert, -12);
		
		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;

		// std::cout << AQUAMARINE << "insert one elem between the 2 previous elem" << RESET << std::endl;
		// std::cout << INDIANRED << "ATTENTION ! Comme on a dépassé la capacité, notre vector a été copié, \nl'itérateur associé n'est plus valable ! Il faut en définir un nv !" << std::endl;
		// ft::vector<int>::iterator itinsert_new = first.begin();
		// first.insert(itinsert_new + 1, 39);

		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;

		// std::cout << AQUAMARINE << "insert one elem at the end of the container" << RESET << std::endl;
		// std::cout << INDIANRED << "ATTENTION ! insert insère les elements juste avant le position spécifiée donc pas besoin de -1 à l'iterator end !" << std::endl;
		// ft::vector<int>::iterator itinsert_end = first.end();
		// first.insert(itinsert_end, -36);

		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;

		// --------------- ERASE ONE ELEM --------------- //		
	// 	std::cout << YELLOW << "erase one elem : " << RESET << std::endl;

	// 			// situation initiale
	// 	std::cout << SILVER << "situation initiale : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
		
	// 			// erase one elem
	// 	std::cout << AQUAMARINE << "erase one elem at position it + 2" << RESET << std::endl;
	// 	ft::vector<int>::iterator iterase = first.begin();
	// 	first.erase(iterase + 2);
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// add several elem until realloc
	// 	std::cout << AQUAMARINE << "add several elem until vector is reallocated" << RESET << std::endl;
	// 	first.push_back(53);
	// 	first.push_back(-12);
	// 	first.push_back(42);
	// 	first.push_back(1);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// erase the last elem
	// 	std::cout << AQUAMARINE << "erase one elem at position it + 4" << RESET << std::endl;
	// 	std::cout << INDIANRED << "ATTENTION ! Comme on a dépassé la capacité, notre vector a été copié, \nl'itérateur associé n'est plus valable ! Il faut en définir un nv !" << std::endl;
	// 	ft::vector<int>::iterator iterase_new = first.begin();
	// 	first.erase(iterase_new + 4);
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// erase all elem
	// 	std::cout << AQUAMARINE << "erase all elem from the container" << RESET << std::endl;
	// 	first.erase(iterase_new + 5);
	// 	first.erase(iterase_new + 4);
	// 	first.erase(iterase_new + 3);
	// 	first.erase(iterase_new + 2);
	// 	first.erase(iterase_new + 1);
	// 	first.erase(iterase_new);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// try to erase an empty container
	// 	std::cout << AQUAMARINE << "try to erase an empty container" << RESET << std::endl;
	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
		
	// 	first.erase(iterase_new);
		
	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// 	std::cout << std::endl;
	// }
	// {
	// 	ft::vector<int> first;
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;






	// // --------------- INSERT RANGE --------------- //
	// 	std::cout << YELLOW << "insert range in position pos : " << RESET << std::endl;

	// 	first.push_back(53);
	// 	first.push_back(-12);

	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

		

	// 			// insert range in position begin
	// 	std::cout << AQUAMARINE << "insert fill in position begin" << RESET << std::endl;
	// 	ft::vector<int>::iterator itinsert_fill = first.begin();
	// 	first.insert(itinsert_fill, 4, 42);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	ft::vector<int> first;
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;








		// // --------------- INSERT FILL --------------- //
		// std::cout << YELLOW << "insert fill with n values at position pos : " << RESET << std::endl;

		// first.push_back(53);
		// first.push_back(-12);
		// first.push_back(42);

		// std::cout << SILVER << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << RESET << std::endl;

		// ft::vector<int> range;
		// range.push_back(-8);
		// range.push_back(92);
		// range.push_back(24);
		// range.push_back(65);
		// range.push_back(112);
		// range.push_back(-2);

		// 		// insert range in position begin
		// std::cout << AQUAMARINE << "insert range in position begin" << RESET << std::endl;
		// ft::vector<int>::iterator itinsert_first = range.begin() + 1;
		// ft::vector<int>::iterator itinsert_range_first = range.begin() + 1;
		// ft::vector<int>::iterator itinsert_range_last = range.begin() + 4;
		// first.insert(itinsert_first, itinsert_range_first, itinsert_range_last);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	ft::vector<int> first;
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 	// --------------- INSERT FILL --------------- //
	// 	std::cout << YELLOW << "insert fill with n values at position pos : " << RESET << std::endl;

	// 	first.push_back(53);
	// 	first.push_back(-12);

	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// insert fill in position middle
	// 	std::cout << AQUAMARINE << "insert fill in position middle" << RESET << std::endl;
	// 	ft::vector<int>::iterator itinsert_fill = first.begin();
	// 	first.insert(itinsert_fill + 1, 4, 42);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	ft::vector<int> first;
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 	// --------------- INSERT FILL --------------- //
	// 	std::cout << YELLOW << "insert fill with n values at position pos : " << RESET << std::endl;

	// 	first.push_back(53);
	// 	first.push_back(-12);

	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// insert fill in position end
	// 	std::cout << AQUAMARINE << "insert fill in position end" << RESET << std::endl;
	// 	ft::vector<int>::iterator itinsert_fill = first.begin();
	// 	first.insert(itinsert_fill + 2, 4, 42);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	// --------------- ERASE RANGE ELEM --------------- //		
	// 	std::cout << YELLOW << "erase range elem: " << RESET << std::endl;
	// 	ft::vector<int> first;
	// 	ft::vector<int>::iterator it_new = first.begin();
	// 	first.push_back(53);
	// 	first.push_back(-12);
	// 	first.push_back(42);
	// 	first.push_back(1);
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << RESET << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	// first.erase(it_new + 1);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << RESET << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << std::endl;




		// // --------------- ASSIGN--------------- //
		// std::cout << YELLOW << "assign : " << RESET << std::endl;
		// first.assign(5, 8);
		// int myints[] = {17, 82, -9};
		// first.assign (myints, myints + 2);

		// std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
	// }
	// {
	// 	std::cout << YELLOW << "Test Constructeur 2 : 5 int with value 8" << RESET << std::endl;
	// 	// param constructor //
	// 	ft::vector<int> second(5, 8);
	// 	std::cout << "max_size of second : " << second.max_size() << std::endl;
	// 	std::cout << std::boolalpha << "is my container second empty ? " << second.empty() << std::endl << std::endl;
	// 	std::cout << YELLOW << "Test Constructeur 4 : a copy of 2" << RESET << std::endl;
	// 	// copy constructor //
	// 	ft::vector<int> fourth(second);
	// 	std::cout << std::boolalpha << "is my container fourth empty ? " << fourth.empty() << std::endl << std::endl;
	// }
	// {
	// 	std::cout << YELLOW << "Test Constructeur 3 : iterating" << RESET << std::endl;
	// 	// param constructor //
	// 	ft::vector<int> vec_param(5, 8);
	// 	std::cout << std::boolalpha << "is my container vec_param empty ? " << vec_param.empty() << std::endl << std::endl;
	// }
	// {
	// 	std::cout << YELLOW << "Test Constructeur 4 : a copy of " << RESET << std::endl;
	// 	// copy constructor //
	// 	ft::vector<int> vec_param(5, 8);
	// 	std::cout << std::boolalpha << "is my container vec_param empty ? " << vec_param.empty() << std::endl << std::endl;
	// }
	// {
	// 	std::cout << RED << "Test Constructeur 2 : vector of ints (param constructor !)" << RESET << std::endl;
	// 	ft::vector<int> first(3);
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 	// --------------- INSERT FILL --------------- //
	// 	std::cout << YELLOW << "insert fill with n values at position pos : " << RESET << std::endl;

	// 	first.push_back(53);
	// 	first.push_back(-12);

	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// insert fill in position middle
	// 	std::cout << AQUAMARINE << "insert fill in position middle" << RESET << std::endl;
	// 	ft::vector<int>::iterator itinsert_fill = first.begin();
	// 	first.insert(itinsert_fill + 1, 4, 42);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 	// ------------ TEST COPY CONSTRUCTOR ----------- //
	// 	std::cout << RED << "Test Constructeur : vector of ints (copy constructor ! init : second = first)" << RESET << std::endl;
	// 	ft::vector<int> second = first;

	// 	std::cout << SILVER << "- size = " << second.size() << "\n- capacity = " << second.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << second.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)second.size(); i++)
	// 		std::cout << second[i] << std::endl;
	// 	std::cout << RESET << std::endl;
		
	// 	// ------------ TEST COPY CONSTRUCTOR, other initialization ----------- //
	// 	std::cout << RED << "Test Constructeur : vector of ints (copy constructor ! init : third(second))" << RESET << std::endl;
	// 	ft::vector<int> third(second);

	// 	std::cout << SILVER << "- size = " << third.size() << "\n- capacity = " << third.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << third.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)third.size(); i++)
	// 		std::cout << third[i] << std::endl;
	// 	std::cout << RESET << std::endl;
		
	// 	ft::vector<int>::iterator it_init = third.begin();
	// 	third.insert(it_init + 2, 21);
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)second.size(); i++)
	// 		std::cout << second[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)third.size(); i++)
	// 		std::cout << third[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	std::cout << RED << "Test Constructeur 2 : vector of ints (param constructor !)" << RESET << std::endl;
	// 	ft::vector<int> first(4, 22);
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 	// --------------- INSERT FILL --------------- //
	// 	std::cout << YELLOW << "insert fill with n values at position pos : " << RESET << std::endl;

	// 	first.push_back(53);
	// 	first.push_back(-12);

	// 	std::cout << SILVER << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 			// insert fill in position middle
	// 	std::cout << AQUAMARINE << "insert fill in position middle" << RESET << std::endl;
	// 	ft::vector<int>::iterator itinsert_fill = first.begin();
	// 	first.insert(itinsert_fill + 1, 4, 42);

	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	// }
	// {
	// 	std::cout << RED << "Test Constructeur 3 : vector of ints (plage d'iterateurs constructor !)" << RESET << std::endl;
	// 	ft::vector<int> first;

	// 	first.push_back(42);
	// 	first.push_back(53);
	// 	first.push_back(-12);
	// 	first.push_back(21);
	// 	first.push_back(-2);
	// 	first.push_back(66);
		
	// 	std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)first.size(); i++)
	// 		std::cout << first[i] << std::endl;
	// 	std::cout << RESET << std::endl;

	// 		// ----- definition des iterateurs debut et fin de la plage que je veux integrer dans mon second vector
	// 	ft::vector<int>::iterator it_first = first.begin() + 1;
	// 	ft::vector<int>::iterator it_last = first.begin() + 4;

	// 	ft::vector<int> second(it_first, it_last);

	// 	std::cout << SILVER << "- size = " << second.size() << "\n- capacity = " << second.capacity()
	// 	<< "\n- containter empty ? " << std::boolalpha << second.empty() <<  std::endl;
	// 	std::cout << "content of the container : " << std::endl;
	// 	for (int i = 0; i < (int)second.size(); i++)
	// 		std::cout << second[i] << std::endl;
	// 	std::cout << RESET << std::endl;
	}
}
