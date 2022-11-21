/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:28:30 by iderighe          #+#    #+#             */
/*   Updated: 2022/11/09 11:49:23 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/* Le trait enable_if contrôle l'application de SFINAE */

/* un trait est une sorte de métadonnée, cad une info disponible au programme sur les types
qui y sont utilisés, obtenue au moment de la compilation. Les traits induisent du polymorphisme
sur la base des types.*/
 
/*SFINAE (Substitution Failure Is Not An Error) est un mécanisme de programmation générique. 
Lorsque le compilateur voit que le code a recours à une fct ou un type génériquem il examine 
les diverses substitutions possibles pour construire son Oversload Setm et conservera la plus
proche de l'intention manifeste du code. */

/* le trait enable_if exprime un type interne et public type. Exemple :
	- std::enable_if< true, T >::type équivaut à T
	- std::enable_if< false, T >::type est indéfini (type incomplet) ce qui peut éliminer un template
		de ceux examinés pdt la génération du code (ou simplement bloquer la compilation.)*/

namespace ft
{
	/*if condition is false, T is void*/
	template< bool B, class T = void >
	struct enable_if
	{};

	/*if condition is true, T is T*/
	template< class T >
	struct enable_if< true, T>
	{
		typedef T type;
	};
}

#endif /* ENABLE_IF_HPP */