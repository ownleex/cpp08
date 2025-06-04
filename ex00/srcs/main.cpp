/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:09:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/04 23:01:04 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    std::cout << std::endl << "=== Test fonction easyfind ===" << std::endl << std::endl;
    
    // Test avec vector
    std::cout << std::endl << "===== Test avec container vector =====" << std::endl << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(100);
    
    std::cout << "Le container contient: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl << std::endl;
    
    // Test reussi - valeur  trouvée
    std::cout << "= Test reussi (recherche valeur 42 et 5) =" << std::endl << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "✅ Valeur 42 trouvée à l'index : " << std::distance(vec.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    
    std::cout << std::endl;
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "✅ Valeur 5 trouvée à l'index : " << std::distance(vec.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    std::cout << std::endl << std::endl;
    
    
    // Test échec - valeur non trouvée
    std::cout << "= Test echec (recherche valeur 999) =" << std::endl << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 999);
        std::cout << "✅ Valeur 999 trouvée à l'index : " << std::distance(vec.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl << std::endl;
    }
    


    // Test avec list
    std::cout << std::endl << std::endl << "===== Test avec container list =====" << std::endl << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(42);
    lst.push_back(100);
    
    std::cout << "Le container contient: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl << std::endl;
    
    // Test reussi - valeur  trouvée
    std::cout << "= Test reussi (recherche valeur 42 et 5) =" << std::endl << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 42);
        std::cout << "✅ Valeur 42 trouvée à l'index : " << std::distance(lst.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    
    std::cout << std::endl;
    
    try {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "✅ Valeur 5 trouvée à l'index : " << std::distance(lst.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    std::cout << std::endl << std::endl;
    
    
    // Test échec - valeur non trouvée
    std::cout << "= Test echec (recherche valeur 999) =" << std::endl << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 999);
        std::cout << "✅ Valeur 999 trouvée à l'index : " << std::distance(lst.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl << std::endl;
    }
    

    
    // Test avec deque
    std::cout << std::endl << std::endl << "===== Test avec container deque =====" << std::endl << std::endl;
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(5);
    dq.push_back(10);
    dq.push_back(42);
    dq.push_back(100);
    
    std::cout << "Le container contient: ";
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl << std::endl;
    
    // Test reussi - valeur  trouvée
    std::cout << "= Test reussi (recherche valeur 42 et 5) =" << std::endl << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(dq, 42);
        std::cout << "✅ Valeur 42 trouvée à l'index : " << std::distance(dq.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    
    std::cout << std::endl;
    
    try {
        std::deque<int>::iterator it = easyfind(dq, 5);
        std::cout << "✅ Valeur 5 trouvée à l'index : " << std::distance(dq.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    std::cout << std::endl << std::endl;
    
    
    // Test échec - valeur non trouvée
    std::cout << "= Test echec (recherche valeur 999) =" << std::endl << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(dq, 999);
        std::cout << "✅ Valeur 999 trouvée à l'index : " << std::distance(dq.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    
    std::cout << std::endl << "=== Fin du test fonction easyfind ===" << std::endl << std::endl;
}