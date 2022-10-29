/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:08:12 by iderighe          #+#    #+#             */
/*   Updated: 2022/10/29 13:11:12 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
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
		std::cout << RED << "Test Constructeur 1 : empty vector of ints (default constructor !)" << RESET << std::endl;
		ft::vector<int> first;
		
		std::cout << SILVER << "résumé de la situation : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		
		std::cout << std::endl << ORANGE << "Test des fonctions du container vector : " << RESET << std::endl;

		// --------------- PUSH_BACK --------------- //		
		std::cout << YELLOW << "push_back : " << RESET << std::endl;
		first.push_back(7);
		// first.push_back(18);
		// first.push_back(-5);
		// first.push_back(-16);

		std::cout << SILVER << "résumé de la situation : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;
		
		// --------------- POP_BACK --------------- //
		std::cout << YELLOW << "pop_back : " << RESET << std::endl;
		first.pop_back();

		std::cout << SILVER << "résumé : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		// --------------- INSERT ONE ELEM  --------------- //
		std::cout << YELLOW << "insert one elem : " << RESET << std::endl;
		std::cout << SILVER << "résumé : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "insert one elem at position it (2 times)" << RESET << std::endl;
		ft::vector<int>::iterator itinsert = first.begin();
		first.insert(itinsert, 27);
		first.insert(itinsert, -12);
		
		std::cout << SILVER << "résumé : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "insert one elem between the 2 previous elem" << RESET << std::endl;
		std::cout << INDIANRED << "ATTENTION ! Comme on a dépassé la capacité, notre vector a été copié, \nl'itérateur associé n'est plus valable ! Il faut en définir un nv !" << std::endl;
		ft::vector<int>::iterator itinsert_new = first.begin();
		first.insert(itinsert_new + 1, 39);

		std::cout << SILVER << "résumé : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		// --------------- ERASE ONE ELEM --------------- //		
		std::cout << YELLOW << "erase one elem : " << RESET << std::endl;

		std::cout << SILVER << "situation initiale : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "erase one elem at position it + 2" << RESET << std::endl;
		ft::vector<int>::iterator iterase = first.begin();
		first.erase(iterase + 2);
		
		std::cout << SILVER << "résumé : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "add several elem until vector is reallocated" << RESET << std::endl;
		first.push_back(53);
		first.push_back(-12);
		first.push_back(42);
		first.push_back(1);

		std::cout << SILVER << "résumé : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "erase one elem at position it + 4" << RESET << std::endl;
		std::cout << INDIANRED << "ATTENTION ! Comme on a dépassé la capacité, notre vector a été copié, \nl'itérateur associé n'est plus valable ! Il faut en définir un nv !" << std::endl;
		ft::vector<int>::iterator iterase_new = first.begin();
		first.erase(iterase_new + 4);
		
		std::cout << SILVER << "résumé de la situation : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "erase all elem from the container" << RESET << std::endl;
		first.erase(iterase_new + 4);
		first.erase(iterase_new + 3);
		first.erase(iterase_new + 2);
		first.erase(iterase_new + 1);
		first.erase(iterase_new);

		std::cout << SILVER << "résumé de la situation : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		std::cout << RESET << std::endl;

		std::cout << AQUAMARINE << "try to erase an empty container" << RESET << std::endl;
		first.erase(iterase_new);
		
		std::cout << std::endl;

		// --------------- INSERT FILL --------------- //
		std::cout << YELLOW << "insert fill with n values at position pos : " << RESET << std::endl;
		first.push_back(53);
		first.push_back(-12);
		ft::vector<int>::iterator itinsert_fill = first.begin();
		first.insert(itinsert_fill + 1, 4, 42);

		// --------------- ERASE RANGE ELEM --------------- //		
		std::cout << YELLOW << "erase range elem: " << RESET << std::endl;
		// ft::vector<int>::iterator it_new = first.begin();
		// first.push_back(53);
		// first.push_back(-12);
		// first.push_back(42);
		// first.push_back(1);
		std::cout << SILVER << "- size = " << first.size() << "\n- capacity = " << first.capacity()
		<< "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		std::cout << "content of the container : " << RESET << std::endl;
		for (int i = 0; i < (int)first.size(); i++)
			std::cout << first[i] << std::endl;
		// first.erase(it_new + 1);

		// std::cout << SILVER << "résumé de la situation : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << RESET << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
		// std::cout << std::endl;




		// // --------------- ASSIGN--------------- //
		// std::cout << YELLOW << "assign : " << RESET << std::endl;
		// first.assign(5, 8);
		// int myints[] = {17, 82, -9};
		// first.assign (myints, myints + 3);

		// std::cout << SILVER << "résumé de la situation : \n- size = " << first.size() << "\n- capacity = " << first.capacity()
		// << "\n- max_size = " << first.max_size() << "\n- containter empty ? " << std::boolalpha << first.empty() <<  std::endl;
		// std::cout << "content of the container : " << std::endl;
		// for (int i = 0; i < (int)first.size(); i++)
		// 	std::cout << first[i] << std::endl;
	}
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
}
