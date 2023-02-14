/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_std.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:08:12 by iderighe          #+#    #+#             */
/*   Updated: 2022/12/07 00:21:08 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <map>
#include <ctime>
// #include <pair>

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


template <class vector1>
void	print_status(vector1 &ft_vect)
{
	std::cout << FUCHSIA << "\t\t    | ---- vector ---- |" << RESET << std::endl;
	std::cout << SILVER << "- size =\t\t" << ft_vect.size() << "\n- capacity =\t\t" << ft_vect.capacity()
	<< "\n- max_size =\t\t" << ft_vect.max_size() << "\n- containter empty ?\t"
	<< std::boolalpha << ft_vect.empty() << std::endl;
	for (int i = 0; i < (int)ft_vect.size(); i++)
			std::cout << "\tcontent[" << i << "]\t" << ft_vect[i] << std::endl;
	std::cout << RESET << std::endl;
}


int	main()
{
	clock_t t = clock();

	{

		std::cout << DARKMAGENTA << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << DARKMAGENTA << "------------------------- TEST DU CONTENEUR VECTOR -------------------------" << RESET << std::endl;
		std::cout << DARKMAGENTA << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << RED << "-------------------------- TEST DES CONSTRUCTEURS --------------------------" << RESET << std::endl;
		std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "Test Constructeur 1 : default constructor !" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "vector d'int ---------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<int> first;
		print_status(first);

		std::cout << "testons une fonction : push_back (on entre la valeur 7)" << std::endl;
		first.push_back(7);
		print_status(first);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<char> second;
		print_status(second);

		std::cout << "testons une fonction : push_back (on entre la valeur 'a')" << std::endl;
		second.push_back('a');
		print_status(second);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<std::string> third;
		print_status(third);

		std::cout << "testons une fonction : push_back (on entre la valeur 'Salut !')" << std::endl;
		third.push_back("Salut !");
		print_status(third);

		std::cout << YELLOW << "vector de float ------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<float> fourth;
		print_status(fourth);

		std::cout << "testons une fonction : push_back (on entre la valeur '42.4221 !')" << std::endl;
		fourth.push_back(42.4221);
		print_status(fourth);
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
		std::vector<int> first(5, 8);
		print_status(first);

		std::cout << "testons une fonction : push_back (on entre la valeur 7)" << std::endl;
		first.push_back(7);
		print_status(first);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<char> second(3, 'b');
		print_status(second);

		std::cout << "testons une fonction : push_back (on entre la valeur 'a')" << std::endl;
		second.push_back('a');
		print_status(second);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<std::string> third(2, "Hello...");
		print_status(third);

		std::cout << "testons une fonction : push_back (on entre la valeur 'Salut !')" << std::endl;
		third.push_back("Salut !");
		print_status(third);

		std::cout << YELLOW << "vector de float ------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<float> fourth(4, 21.2121);
		print_status(fourth);

		std::cout << "testons une fonction : push_back (on entre la valeur '42.4221 !')" << std::endl;
		fourth.push_back(42.4242);
		print_status(fourth);
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
		std::vector<int> first;
		first.push_back(42);
		first.push_back(53);
		first.push_back(-12);
		first.push_back(21);
		first.push_back(-2);
		first.push_back(66);

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(first);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		std::vector<int>::iterator itf_ft_begin = first.begin() + 1;
		std::vector<int>::iterator itf_ft_end = first.begin() + 4;

		std::vector<int> first_range(itf_ft_begin, itf_ft_end);
		print_status(first);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<char> second;
		second.push_back('a');
		second.push_back('b');
		second.push_back('c');
		second.push_back('d');
		second.push_back('e');
		second.push_back('f');

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(second);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		std::vector<char>::iterator its_ft_begin = second.begin() + 1;
		std::vector<char>::iterator its_ft_end = second.begin() + 4;

		std::vector<char> second_range(its_ft_begin, its_ft_end);
		print_status(second);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<std::string> third;
		third.push_back("Salut");
		third.push_back("Bonjour");
		third.push_back("Ciao");
		third.push_back("Hello");
		third.push_back("Guten tag");
		third.push_back("Grumph");

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(third);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		std::vector<std::string>::iterator itt_ft_begin = third.begin() + 1;
		std::vector<std::string>::iterator itt_ft_end = third.begin() + 4;

		std::vector<std::string> third_range(itt_ft_begin, itt_ft_end);
		print_status(third);

		std::cout << YELLOW << "vector de float ------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<float> fourth;
		fourth.push_back(42.123);
		fourth.push_back(53.456);
		fourth.push_back(-12.789);
		fourth.push_back(21.741);
		fourth.push_back(-2.852);
		fourth.push_back(66.963);

		std::cout << PALETURQUOISE << "on cree un vector de base et on le remplit de 6 valeurs" << RESET << std::endl;
		print_status(fourth);

		std::cout << PALETURQUOISE << "definition des iterateurs debut et fin de la plage puis creation d'un nv vector avec la plage" << RESET << std::endl;
		std::vector<float>::iterator itfo_ft_begin = fourth.begin() + 1;
		std::vector<float>::iterator itfo_ft_end = fourth.begin() + 4;

		std::vector<float> fourth_range(itfo_ft_begin, itfo_ft_end);
		print_status(fourth);
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
		std::vector<int> first(5, 8);
		

		std::cout << PALETURQUOISE << "\n2 types d'appel au copy constructor : vector<> cpy = vct et vector<> vct(vct)" << RESET << std::endl;

		std::vector<int> f_cpy_equal = first;

		f_cpy_equal.push_back(7);

		std::vector<int> f_cpy_param(f_cpy_equal);

		f_cpy_param.push_back(5);

		std::cout << "testons une fonction : push_back (on entre la valeur 7 dans les copies equal et 5 dans les copies param des copies equal!)" << std::endl;
		std::cout << SILVER << "vectors originaux : " << std::endl; 
		print_status(first);
		std::cout << SILVER << "vectors copy equal : " << std::endl; 
		print_status(f_cpy_equal);
		std::cout << SILVER << "vectors copy param : " << std::endl; 
		print_status(f_cpy_param);

		std::cout << YELLOW << "vector de char -------------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<char> second(3, 'b');

		std::cout << PALETURQUOISE << "\n2 types d'appel au copy constructor : vector<> cpy = vct et vector<> cpy(vct)" << RESET << std::endl;

		std::vector<char> s_cpy_equal = second;

		s_cpy_equal.push_back('i');

		std::vector<char> s_cpy_param(s_cpy_equal);

		s_cpy_param.push_back('j');

		std::cout << "testons une fonction : push_back (on entre la valeur 'i' dans les copies equal et 'j' dans les copies param des copies equal!)" << std::endl;
		std::cout << SILVER << "vectors originaux : " << std::endl; 
		print_status(second);
		std::cout << SILVER << "vectors copy equal : " << std::endl; 
		print_status(s_cpy_equal);
		std::cout << SILVER << "vectors copy param : " << std::endl; 
		print_status(s_cpy_param);

		std::cout << YELLOW << "vector de string -----------------------------------------------------------" << RESET << std::endl << std::endl;
		std::vector<std::string> third;
		third.push_back("Salut");
		third.push_back("Bonjour");
		third.push_back("Ciao");
		third.push_back("Hello");
		third.push_back("Guten tag");

		try
		{
			std::cout << third.at(7) << std::endl;
		}
		catch(std::exception &e){std::cout <<  e.what() << std::endl;}

		std::cout << PALETURQUOISE << "\n2 types d'appel au copy constructor : vector<> cpy = vct et vector<> cpy(vct)" << RESET << std::endl;

		std::vector<std::string> t_cpy_equal = third;

		t_cpy_equal.push_back("blablabla");

		std::vector<std::string> t_cpy_param(t_cpy_equal);

		t_cpy_param.push_back("Grumph");

		std::cout << "testons une fonction : push_back (on entre la valeur 'i' dans les copies equal et 'j' dans les copies param des copies equal!)" << std::endl;
		std::cout << SILVER << "vectors originaux : " << std::endl; 
		print_status(third);
		std::cout << SILVER << "vectors copy equal : " << std::endl; 
		print_status(t_cpy_equal);
		std::cout << SILVER << "vectors copy param : " << std::endl; 
		print_status(t_cpy_param);
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
			std::vector<int> first;
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			std::vector<int> first;
			first.assign(4, 21);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			std::vector<int> first;
			std::vector<int> second(7, 13);

			std::vector<int>::iterator begin = second.begin() + 1;
			std::vector<int>::iterator end = second.begin() + 4;
			
			
			first.assign(begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			std::vector<int> first;
			
			first.push_back(42);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : sur container vide -> undefined behavior" << RESET << std::endl;
			std::vector<int> first;
			
			first.pop_back();
			print_status(first);
			// try
			// 	{std::cout << first[5] << std::endl;}
			// catch (std::exception &e)
			// 	{std::cout << e.what() << std::endl;}
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::vector<int> first;
			
			std::vector<int>::iterator itinsert = first.begin();
			
			first.insert(itinsert, 27);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::vector<int> first;
			
			std::vector<int>::iterator itinsert = first.begin();
			
			first.insert(itinsert, 4, 42);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::vector<int> first;

			std::vector<int> second(7, 13);

			std::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator begin = second.begin() + 1;
			std::vector<int>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<int> first;
			
			std::cout << INDIANRED << "ATTENTION : erase sur un vector standard vide = crash ! try / catch !" << RESET << std::endl;
			// try
			// {
			// 	std::vector<int>::iterator iterase = first.begin();
			// 	first.erase(iterase);
			// }
			// catch(std::exception &e) {
			// 	std::cout << "test (erase sur vector standard vide) : " << e.what() << std::endl; }

			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<int> first;
			
			std::vector<int>::iterator iterase_first = first.begin();
			std::vector<int>::iterator iterase_last = first.end();

			first.erase(iterase_first, iterase_last);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<int> first;
			std::vector<int> second;

			print_status(first);
			print_status(second);

			first.swap(second);
		
			print_status(first);
			print_status(second);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<int> first;
			
			first.clear();
			print_status(first);
		}


		std::cout << std::endl << std::endl; 
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur vector initialisé (constructeur par param)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "situation initiale : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			
			first.assign(4, 21);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			std::vector<int> second(7, 13);

			print_status(first);
			print_status(second);

			std::vector<int>::iterator begin = second.begin() + 1;
			std::vector<int>::iterator end = second.begin() + 4;

			first.assign(begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			first.push_back(42);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			first.pop_back();
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator itinsert = first.begin();

			first.insert(itinsert, 27);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator itinsert = first.begin() + 2;

			first.insert(itinsert, 27);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator itinsert = first.end();

			first.insert(itinsert, 27);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator itinsert = first.begin();

			first.insert(itinsert, 4, 42);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator itinsert = first.begin() + 3;

			first.insert(itinsert, 4, 42);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator itinsert = first.end();

			first.insert(itinsert, 4, 42);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			std::vector<int> second(7, 13);
			
			print_status(first);
			print_status(second);

			std::vector<int>::iterator itinsert = first.begin();
			std::vector<int>::iterator begin = second.begin() + 1;
			std::vector<int>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			std::vector<int> second(7, 13);

			std::vector<int>::iterator itinsert = first.begin() + 3;
			std::vector<int>::iterator begin = second.begin() + 1;
			std::vector<int>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			std::vector<int> second(7, 13);

			std::vector<int>::iterator itinsert = first.end();
			std::vector<int>::iterator begin = second.begin() + 1;
			std::vector<int>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator iterase = first.begin();

			first.erase(iterase);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : " << RESET << std::endl;
			std::vector<int> first(5, 8);

			std::vector<int>::iterator iterase_first = first.begin();
			std::vector<int>::iterator iterase_last = first.begin() + 2;

			first.erase(iterase_first, iterase_last);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			std::vector<int> second(3, 13);

			first.swap(second);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : " << RESET << std::endl;
			std::vector<int> first(5, 8);
			first.clear();
			print_status(first);
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
			std::vector<std::string> first;
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			std::vector<std::string> first;
			first.assign(4, "salut !");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			std::vector<std::string> first;
			std::vector<std::string> second(7, "Hello");

			print_status(first);
			print_status(second);

			std::vector<std::string>::iterator begin = second.begin() + 1;
			std::vector<std::string>::iterator end = second.begin() + 4;
			
			first.assign(begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			std::vector<std::string> first;
			first.push_back("Coucou !");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<std::string> first;

			std::cout << INDIANRED << "ATTENTION : pop_back sur un vector standard de string vide = crash !" << RESET << std::endl;
			// first.pop_back();
			// print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::vector<std::string> first;

			std::vector<std::string>::iterator itinsert = first.begin();

			first.insert(itinsert, "Hello World");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::vector<std::string> first;

			std::vector<std::string>::iterator itinsert = first.begin();

			first.insert(itinsert, 4, "Grumph");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::vector<std::string> first;
			std::vector<std::string> second(7, "Salut !");
			
			print_status(first);
			print_status(second);

			std::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator begin = second.begin() + 1;
			std::vector<std::string>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<std::string> first;

			std::cout << INDIANRED << "ATTENTION : erase sur un vector standard vide = crash !" << RESET << std::endl;
			// std::vector<std::string>::iterator iterase = first.begin();
			// first.erase(iterase);
			// print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<std::string> first;

			std::vector<std::string>::iterator iterase_first = first.begin();
			std::vector<std::string>::iterator iterase_last = first.end();

			first.erase(iterase_first, iterase_last);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<std::string> first;
			std::vector<std::string> second;

			first.swap(second);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : pas tres utile sur un container vide... mais ça crash pas ! " << RESET << std::endl;
			std::vector<std::string> first;
			first.clear();
			print_status(first);
		}



		std::cout << std::endl << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur vector initialisé (constructeur par param)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "situation initiale : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype fill) : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			print_status(first);

			first.assign(4, "Guten tag.");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction assign (prototype range) : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			std::vector<std::string> second(7, "Hello");
			
			print_status(first);
			print_status(second);

			std::vector<std::string>::iterator begin = second.begin() + 1;
			std::vector<std::string>::iterator end = second.begin() + 4;
			
			first.assign(begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction push_back : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			first.push_back("Coucou !");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction pop_back : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			first.pop_back();
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			print_status(first);

			std::vector<std::string>::iterator itinsert = first.begin();
			first.insert(itinsert, "Hello World");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator itinsert = first.begin() + 3;
			
			first.insert(itinsert, "Hello World");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype single) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator itinsert = first.end();
			
			first.insert(itinsert, "Hello World");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator itinsert = first.begin();
			
			first.insert(itinsert, 4, "Grumph");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator itinsert = first.begin() + 2;
			
			first.insert(itinsert, 4, "Grumph");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype fill) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator itinsert = first.end();
			
			first.insert(itinsert, 4, "Grumph");
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in first position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			std::vector<std::string> second(7, "Grumph");
			
			std::vector<std::string>::iterator itinsert = first.begin();
			std::vector<std::string>::iterator begin = second.begin() + 1;
			std::vector<std::string>::iterator end = second.begin() + 4;
			
			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			std::vector<std::string> second(7, "Grumph");
			
			std::vector<std::string>::iterator itinsert = first.begin() + 3;
			std::vector<std::string>::iterator begin = second.begin() + 1;
			std::vector<std::string>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in last position : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			std::vector<std::string> second(7, "Grumph");
			
			std::vector<std::string>::iterator itinsert = first.end();
			std::vector<std::string>::iterator begin = second.begin() + 1;
			std::vector<std::string>::iterator end = second.begin() + 4;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype single) : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator iterase = first.begin();
			
			first.erase(iterase);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction erase (prototype range) : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			
			std::vector<std::string>::iterator iterase_first = first.begin() + 2;
			std::vector<std::string>::iterator iterase_last = first.end();
			
			first.erase(iterase_first, iterase_last);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction swap : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			std::vector<std::string> second(3, "Hello...");
			
			first.swap(second);
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction clear : " << RESET << std::endl;
			std::vector<std::string> first(5, "Salut !");
			first.clear();
			print_status(first);
		}
		{
			std::cout << PALETURQUOISE << "\ntest de la fonction insert (prototype range) : " << RESET << std::endl;
			std::cout << SPRINGGREEN << "	-> insert in middle position : " << RESET << std::endl;
			std::vector<std::string> first;
			first.push_back("Salut !");
			first.push_back("Guten Tag.");
			first.push_back("Glebeskefe");
			first.push_back("Hello World :D");
			first.push_back("Ciao");

			std::vector<std::string> second;
			second.push_back("Baba");
			second.push_back("Bebe");
			second.push_back("Bibi");
			second.push_back("Bobo");
			second.push_back("Bubu");

			print_status(first);
			print_status(second);

			std::vector<std::string>::iterator itinsert = first.begin() + 2;
			std::vector<std::string>::reverse_iterator begin = second.rbegin();
			std::vector<std::string>::reverse_iterator end = second.rend();
			
			std::cout << "valeur contenue dans iterator rbegin : " << *second.rbegin() << std::endl;
			std::cout << "valeur contenue dans iterator rend : " << *(second.rend() - 1) << std::endl;

			first.insert(itinsert, begin, end);
			print_status(first);
		}
	}



	std::cout << std::endl;
	std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl;
	std::cout << RED << "-------------------- TEST VECTOR : RELATIONAl OPERATORS --------------------" << RESET << std::endl;
	std::cout << RED << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

	std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
	std::cout << ORANGE << "		Test vector d'int" << RESET << std::endl;
	std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

	std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
	std::cout << YELLOW << "Sur vector vide (constructeur par défaut)" << RESET << std::endl;
	std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
	{
		std::cout << PALETURQUOISE << "\ntest des relational operators (non member functions) : " << RESET << std::endl;
		std::vector<int> first;
		first.push_back(42);

		std::vector<int> second;
		second.push_back(42);

		std::cout << SPRINGGREEN << "test operator ==" << RESET << std::endl;
		std::cout << first.back() << " | " << second.back() << std::endl;
		std::cout << "std : ";
		if (first == second)
			std::cout << "oui" << std::endl;
		else
			std::cout << "non" << std::endl;
		
		std::cout << SPRINGGREEN << "test operator !=" << RESET << std::endl;
		std::cout << first.back() << " | " << second.back() << std::endl;
		std::cout << "std : ";
		if (first != second)
			std::cout << "oui" << std::endl;
		else
			std::cout << "non" << std::endl;
		
		first.push_back(21);
		second.push_back(84);

		std::cout << SPRINGGREEN << "test operator <" << RESET << std::endl;
		std::cout << first.back() << " | " << second.back() << std::endl;
		std::cout << "std : ";
		if (first < second)
			std::cout << "oui" << std::endl;
		else
			std::cout << "non" << std::endl;
		
		std::cout << SPRINGGREEN << "test operator >" << RESET << std::endl;
		std::cout << first.back() << " | " << second.back() << std::endl;
		std::cout << "std : ";
		if (first > second)
			std::cout << "oui" << std::endl;
		else
			std::cout << "non" << std::endl;
	}



	{
		std::cout << std::endl;
		std::cout << DARKMAGENTA << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << DARKMAGENTA << "------------------------- TEST DU CONTAINER STACK --------------------------" << RESET << std::endl;
		std::cout << DARKMAGENTA << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "		Test stack d'int" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur stack vide (constructeur par défaut)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "\ntest des fonctions push et pop / affichage des résultats de empty / size / top : " << RESET << std::endl;
			std::stack<int> first;
			first.push(42);

			std::cout << SPRINGGREEN << "push 42" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;

			first.push(21);

			std::cout << SPRINGGREEN << "push 21" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;

			first.push(-13);

			std::cout << SPRINGGREEN << "push -13" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;

			first.pop();

			std::cout << SPRINGGREEN << "pop dernier element (ici : -13) car LIFO (last in - first out" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "		Test stack de string" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur stack vide (constructeur par défaut)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "\ntest des fonctions push et pop / affichage des résultats de empty / size / top : " << RESET << std::endl;
			std::stack<std::string> first;
			first.push("Salut");

			std::cout << SPRINGGREEN << "push Salut" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;

			first.push("Hello World !");

			std::cout << SPRINGGREEN << "push Hello World !" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;

			first.push("Grumph...");

			std::cout << SPRINGGREEN << "push Grumph..." << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;

			first.pop();

			std::cout << SPRINGGREEN << "pop dernier element (ici : Grumph...) car LIFO (last in - first out" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ----- my stack (std) ---- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << first.size() << "\n- containter empty ?\t"
			<< std::boolalpha << first.empty() << std::endl
			<< "- top value =\t\t" << first.top() << std::endl;
			std::cout << RESET << std::endl;
		}

		std::cout << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "		Test stack de int" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << YELLOW << "Sur stack vide (constructeur par défaut)" << RESET << std::endl;
		std::cout << YELLOW << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "\ntest des relational operators (non member functions) : " << RESET << std::endl;
			std::stack<int> first;
			first.push(42);

			std::stack<int> second;
			second.push(42);

			std::cout << SPRINGGREEN << "test operator ==" << RESET << std::endl;
			std::cout << first.top() << " | " << second.top() << std::endl;
			std::cout << "std : ";
			if (first == second)
				std::cout << "oui" << std::endl;
			else
				std::cout << "non" << std::endl;
			
			std::cout << SPRINGGREEN << "test operator !=" << RESET << std::endl;
			std::cout << first.top() << " | " << second.top() << std::endl;
			std::cout << "std : ";
			if (first != second)
				std::cout << "oui" << std::endl;
			else
				std::cout << "non" << std::endl;
			
			first.push(21);
			second.push(84);

			std::cout << SPRINGGREEN << "test operator <" << RESET << std::endl;
			std::cout << first.top() << " | " << second.top() << std::endl;
			std::cout << "std : ";
			if (first < second)
				std::cout << "oui" << std::endl;
			else
				std::cout << "non" << std::endl;
			
			std::cout << SPRINGGREEN << "test operator >" << RESET << std::endl;
			std::cout << first.top() << " | " << second.top() << std::endl;
			std::cout << "std : ";
			if (first > second)
				std::cout << "oui" << std::endl;
			else
				std::cout << "non" << std::endl;
		}
	}



	{
		std::cout << std::endl;
		std::cout << DARKMAGENTA << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << DARKMAGENTA << "-------------------------- TEST DU CONTAINER MAP ---------------------------" << RESET << std::endl;
		std::cout << DARKMAGENTA << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
		std::cout << ORANGE << "		Test de la classe pair" << RESET << std::endl;
		std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;
		{
			std::cout << PALETURQUOISE << "\ntest de la classe pair : " << RESET << std::endl;
			std::pair <std::string,double> product1;                     // default constructor
			std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
			std::pair <std::string,double> product3 (product2);          // copy constructor

			product2.first = "shoes";                  // the type of first is string
			product2.second = 39.90;                   // the type of second is double

			std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
			std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
			std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
		}

		{
			std::cout << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
			std::cout << ORANGE << "		Map : Constructeur par défaut + insert single" << RESET << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

			std::map<int, std::string> ft_map;
			ft_map.insert(std::make_pair(5, "ROOT"));
			ft_map.insert(std::make_pair(2, "BEGIN"));
			ft_map.insert(std::make_pair(10, "END"));
			ft_map.insert(std::make_pair(8, "RDM"));
			ft_map.insert(std::make_pair(2, "NEW"));

			std::map<int, std::string>::iterator ft_it = ft_map.begin();
			std::map<int, std::string>::iterator ft_ite = ft_map.end();

			std::cout << SPRINGGREEN << "affichage contenu de map" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ------ container map ----- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << ft_map.size() << "\n- containter empty ?\t"
			<< std::boolalpha << ft_map.empty() << std::endl;

			std::cout << std::endl;

			size_t i = 0;
			while (i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second;
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << std::endl;
				i++;
			}

			std::cout << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << ft_map.size() << RESET << std::endl;
		}
		{
			std::cout << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
			std::cout << ORANGE << "		Map : Constructeur par défaut + insert range" << RESET << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

			std::cout << PALETURQUOISE << "\ntest de la std::map : " << RESET << std::endl;

			std::map<int, std::string> ft_map;

			std::map<int, std::string> ft_map2;
			ft_map2.insert(std::make_pair(5, "ROOT"));
			ft_map2.insert(std::make_pair(2, "BEGIN"));
			ft_map2.insert(std::make_pair(10, "END"));
			ft_map2.insert(std::make_pair(8, "RDM"));
			ft_map2.insert(std::make_pair(2, "NEW"));
			
			std::map<int, std::string>::iterator ft2_it = ft_map2.begin();
			std::map<int, std::string>::iterator ft2_ite = ft_map2.end();

			ft_map.insert(ft2_it, ft2_ite);

			std::cout << SPRINGGREEN << "affichage contenu de map" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ------ map copy ----- | ------ map source ----- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << ft_map.size() << std::setw(27) << ft_map2.size() << "\n- containter empty ?\t"
			<< std::boolalpha << ft_map.empty() << std::setw(27) << ft_map2.empty() << std::endl;

			std::cout << std::endl;
			std::map<int, std::string>::iterator ft_it = ft_map.begin();
			std::map<int, std::string>::iterator ft_ite = ft_map.end();
			ft_map.insert(++ft_it, std::make_pair(7, "TEST"));
			ft_it--;
			ft_map2.insert(++ft2_it, std::make_pair(7, "TEST"));
			ft2_it--;
			size_t i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second;
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << "\t\t   ";
				if (ft2_it != ft2_ite) {
					std::cout << ft2_it->first << " | " <<  ft2_it->second;
					ft2_it++; }
				std::cout << std::endl;
				i++;
			}
		}
		{
			std::cout << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
			std::cout << ORANGE << "		Map : test de erase" << RESET << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

			std::map<int, std::string> ft_map;

			std::map<int, std::string> ft_map2;
			ft_map2.insert(std::make_pair(5, "ROOT"));
			ft_map2.insert(std::make_pair(2, "Aisne"));
			ft_map2.insert(std::make_pair(10, "Aube"));
			ft_map2.insert(std::make_pair(8, "Ardennes"));
			ft_map2.insert(std::make_pair(2, "NEW"));
			ft_map2.insert(std::make_pair(15, "END"));
			ft_map2.insert(std::make_pair(7, "Ardeche"));
			ft_map2.insert(std::make_pair(3, "Allier"));
			ft_map2.insert(std::make_pair(1, "BEGIN"));
			ft_map2.insert(std::make_pair(9, "Ariege"));
			
			std::map<int, std::string>::iterator ft2_it = ft_map2.begin();
			std::map<int, std::string>::iterator ft2_ite = ft_map2.end();

			ft_map.insert(ft2_it, ft2_ite);

			std::cout << std::endl;
			std::map<int, std::string>::iterator ft_it = ft_map.begin();
			std::map<int, std::string>::iterator ft_ite = ft_map.end();
			ft_map.insert(++ft_it, std::make_pair(12, "Aveyron"));
			ft_it--;
			ft_map2.insert(++ft2_it, std::make_pair(12, "Aveyron"));
			ft2_it--;
			
			std::cout << SPRINGGREEN << "affichage contenu de map" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ------ map copy ----- | ------ map source ----- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << ft_map.size() << std::setw(27) << ft_map2.size() << "\n- containter empty ?\t"
			<< std::boolalpha << ft_map.empty() << std::setw(27) << ft_map2.empty() << std::endl;

			size_t i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second;
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << "\t\t   ";
				if (ft2_it != ft2_ite) {
					std::cout << ft2_it->first << " | " <<  ft2_it->second;
					ft2_it++; }
				std::cout << std::endl;
				i++;
			}

			std::cout << std::endl << std::endl;
			std::cout << PALETURQUOISE << "\ntest de erase single position : " << RESET << std::endl;

			ft_map.erase(ft_map.begin());
			ft_it = ft_map.begin();
			ft_ite = ft_map.end();
			i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second << " | " << ft_map.size();
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << "\t\t   ";
				if (ft2_it != ft2_ite) {
					std::cout << ft2_it->first << " | " <<  ft2_it->second;
					ft2_it++; }
				std::cout << std::endl;
				i++;
			}

			std::cout << std::endl << std::endl;
			std::cout << PALETURQUOISE << "\ntest de erase key : " << RESET << std::endl;

			ft_map.erase(3);
			ft_it = ft_map.begin();
			ft_ite = ft_map.end();
			i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second << " | " << ft_map.size();
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << "\t\t   ";
				if (ft2_it != ft2_ite) {
					std::cout << ft2_it->first << " | " <<  ft2_it->second;
					ft2_it++; }
				std::cout << std::endl;
				i++;
			}

			std::cout << std::endl << std::endl;
			std::cout << PALETURQUOISE << "\ntest de erase range : " << RESET << std::endl;

			ft_it = ft_map.begin();
			ft_it++;
			ft_ite = ft_map.end();
			ft_ite--;
			ft_map.erase(++ft_it, --ft_ite);

			ft_it = ft_map.begin();
			ft_ite = ft_map.end();
			i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second << " | " << ft_map.size();
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << std::endl;
				i++;
			}

			std::cout << std::endl << std::endl;
			std::cout << PALETURQUOISE << "\ntest de clear : " << RESET << std::endl;

			ft_it = ft_map.begin();
			ft_ite = ft_map.end();
			ft_map.clear();

			ft_it = ft_map.begin();
			ft_ite = ft_map.end();
			ft2_it = ft_map2.begin();
			ft2_ite = ft_map2.end();
			i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second << " | " << ft_map.size();
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << "\t\t   ";
				if (ft2_it != ft2_ite) {
					std::cout << ft2_it->first << " | " <<  ft2_it->second;
					ft2_it++; }
				std::cout << std::endl;
				i++;
			}
		}
		{
			std::cout << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
			std::cout << ORANGE << "		Map : constructeur par plage" << RESET << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

			std::map<int, std::string> ft_map;
			ft_map.insert(std::make_pair(5, "ROOT"));
			ft_map.insert(std::make_pair(2, "Aisne"));
			ft_map.insert(std::make_pair(10, "Aube"));
			ft_map.insert(std::make_pair(8, "Ardennes"));
			ft_map.insert(std::make_pair(2, "NEW"));
			ft_map.insert(std::make_pair(15, "END"));
			ft_map.insert(std::make_pair(7, "Ardeche"));
			ft_map.insert(std::make_pair(3, "Allier"));
			ft_map.insert(std::make_pair(1, "BEGIN"));
			ft_map.insert(std::make_pair(9, "Ariege"));
			
			std::map<int, std::string>::iterator ft_it = ft_map.begin();
			std::map<int, std::string>::iterator ft_ite = ft_map.end();

			std::map<int, std::string> ft_map2(ft_it, ft_ite);

			std::cout << SPRINGGREEN << "affichage contenu de map constructor range" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ------ container map ----- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << ft_map.size() << "\n- containter empty ?\t"
			<< std::boolalpha << ft_map.empty() << std::endl;

			std::cout << std::endl;
			std::map<int, std::string>::iterator ft2_it = ft_map2.begin();
			std::map<int, std::string>::iterator ft2_ite = ft_map2.end();
			size_t i = 0;
			while (i < ft_map2.size() || i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second;
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << "\t\t   ";
				if (ft2_it != ft2_ite) {
					std::cout << ft2_it->first << " | " <<  ft2_it->second;
					ft2_it++; }
				std::cout << std::endl;
				i++;
			}
		}
		{
			std::cout << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl;
			std::cout << ORANGE << "		Map : fonctions operations" << RESET << std::endl;
			std::cout << ORANGE << "----------------------------------------------------------------------------" << RESET << std::endl << std::endl;

			std::map<int, std::string> ft_map;
			ft_map.insert(std::make_pair(5, "ROOT"));
			ft_map.insert(std::make_pair(2, "BEGIN"));
			ft_map.insert(std::make_pair(10, "Aube"));
			ft_map.insert(std::make_pair(8, "Ardennes"));
			ft_map.insert(std::make_pair(2, "NEW"));
			ft_map.insert(std::make_pair(15, "END"));
			ft_map.insert(std::make_pair(7, "Ardeche"));
			ft_map.insert(std::make_pair(3, "Allier"));
			ft_map.insert(std::make_pair(9, "Ariege"));
			
			std::cout << SPRINGGREEN << "affichage contenu de map constructor range" << RESET << std::endl;
			std::cout << FUCHSIA << "\t\t    | ------ container map ----- |" << RESET << std::endl;
			std::cout << SILVER << "- size =\t\t" << ft_map.size() << "\n- containter empty ?\t"
			<< std::boolalpha << ft_map.empty() << std::endl;

			std::cout << std::endl;
			std::map<int, std::string>::iterator ft_it = ft_map.begin();
			std::map<int, std::string>::iterator ft_ite = ft_map.end();
			size_t i = 0;
			while (i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second << " | " << ft_map.size();
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << std::endl;
				i++;
			}
			
			std::cout << std::endl;
			std::cout << PALETURQUOISE << "\ntest de lower_bound : " << RESET << std::endl;

			std::cout << "test de lower_bound : " << ft_map.lower_bound(2)->first << std::endl;
			std::cout << "test de lower_bound : " << ft_map.lower_bound(10)->first << std::endl;
			std::cout << "test de lower_bound : " << ft_map.lower_bound(1)->first << std::endl;
			std::cout << "test de lower_bound : " << ft_map.lower_bound(20)->first << std::endl;

			std::cout << std::endl;
			std::cout << PALETURQUOISE << "\ntest de upper_bound : " << RESET << std::endl;

			std::cout << "test de upper_bound : " << ft_map.upper_bound(2)->first << std::endl;
			std::cout << "test de upper_bound : " << ft_map.upper_bound(10)->first << std::endl;
			std::cout << "test de upper_bound : " << ft_map.upper_bound(1)->first << std::endl;
			std::cout << "test de upper_bound : " << ft_map.upper_bound(20)->first << std::endl;

			std::cout << std::endl;
			std::cout << PALETURQUOISE << "\ntest de equal_range : " << RESET << std::endl;

			std::cout << "test de equal_range : " << ft_map.equal_range(2).first->first << std::endl;
			std::cout << "test de equal_range : " << ft_map.equal_range(10).first->first << std::endl;
			std::cout << "test de equal_range : " << ft_map.equal_range(1).first->first << std::endl;
			std::cout << "test de equal_range : " << ft_map.equal_range(20).first->first << std::endl;

			std::cout << std::endl;
			std::cout << PALETURQUOISE << "\ntest de operator[] : " << RESET << std::endl;

			std::cout << "test operator[2] : " << ft_map[2] << std::endl;
			std::cout << "test operator[10] : " << ft_map[10] << std::endl;
			std::cout << "test operator[1] : " << ft_map[1] << std::endl;
			std::cout << "test operator[20] : " << ft_map[20] << std::endl;

			std::cout << std::endl;
			std::cout << PALETURQUOISE << "\ntest de at() : " << RESET << std::endl;

			std::cout << "test at(2) : " << ft_map.at(2) << std::endl;
			std::cout << "test at(10) : " << ft_map.at(10) << std::endl;
			try {
				std::cout << "test at(1) : " << ft_map.at(1) << std::endl; }
			catch(std::exception &e) {
				std::cout << "test at(1) : " << e.what() << std::endl; }
			try {
				std::cout << "test at(20) : " << ft_map.at(20) << std::endl; }
			catch(std::exception &e) {
				std::cout << "test at(20) : " << e.what() << std::endl; }

			ft_map[56] = "Morbihan";

			std::cout << std::endl;

			ft_it = ft_map.begin();
			ft_ite = ft_map.end();
			i = 0;
			while (i < ft_map.size())
			{
				std::cout << "\t\t\t";
				if (ft_it != ft_ite) {
					std::cout << ft_it->first << " | " <<  ft_it->second << " | " << ft_map.size();
					ft_it++; }
				else {
					std::cout << "\t"; }
				std::cout << std::endl;
				i++;
			}
		}
	}

	t = clock() - t;
	std::cout << std::endl << std::endl << GOLD << "Temps d'execution du programme : " << (((float)t/CLOCKS_PER_SEC) * 1000) << " millisecondes."<< RESET << std::endl;
}
