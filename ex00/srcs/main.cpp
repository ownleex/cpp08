/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:09:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/01 22:37:19 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::cout << std::endl << "=== Test fonction easyfind ===" << std::endl << std::endl;
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(100);
    
    std::cout << "Le container contient: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl << std::endl;
    
    // Test reussi - valeur  trouvée
    std::cout << "= Test reussi (recherche valeur 42 et 5) =" << std::endl << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "✅ Valeur 42 trouvée à la position: " << std::distance(vec.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    
    std::cout << std::endl;
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "✅ Valeur 5 trouvée à la position: " << std::distance(vec.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    std::cout << std::endl << std::endl;
    
    
    // Test échec - valeur non trouvée
    std::cout << "= Test echec (recherche valeur 999) =" << std::endl << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 999);
        std::cout << "✅ Valeur 999 trouvée à la position: " << std::distance(vec.begin(), it) << " ✅" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Erreur: " << e.what() << " ❌"<< std::endl;
    }
    
    std::cout << std::endl << "=== Fin du test fonction easyfind ===" << std::endl << std::endl;
}

/*
void testVector()
{
    std::cout << "=== Test avec std::vector ===" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(42);
    vec.push_back(100);
    
    std::cout << "Vecteur contient: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Test réussi - valeur trouvée
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Valeur 42 trouvée à la position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test réussi - première occurrence
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Valeur 5 trouvée à la position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test échec - valeur non trouvée
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 999);
        std::cout << "Valeur 999 trouvée à la position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur attendue: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testList()
{
    std::cout << "=== Test avec std::list ===" << std::endl;
    
    std::list<int> lst;
    lst.push_back(7);
    lst.push_back(14);
    lst.push_back(21);
    lst.push_back(28);
    
    std::cout << "Liste contient: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Test réussi
    try
    {
        easyfind(lst, 21);
        std::cout << "Valeur 21 trouvée dans la liste" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test échec
    try
    {
        easyfind(lst, 50);
        std::cout << "Valeur 50 trouvée dans la liste" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur attendue: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testDeque()
{
    std::cout << "=== Test avec std::deque ===" << std::endl;
    
    std::deque<int> dq;
    dq.push_back(100);
    dq.push_back(200);
    dq.push_back(300);
    dq.push_front(50);
    
    std::cout << "Deque contient: ";
    for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    // Test avec const
    const std::deque<int> const_dq = dq;
    try
    {
        easyfind(const_dq, 200);
        std::cout << "Valeur 200 trouvée dans la deque const" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testEdgeCases()
{
    std::cout << "=== Tests de cas limites ===" << std::endl;
    
    // Test avec conteneur vide
    std::vector<int> empty_vec;
    try
    {
        easyfind(empty_vec, 1);
    }
    catch (const std::exception& e)
    {
        std::cout << "Conteneur vide - Erreur attendue: " << e.what() << std::endl;
    }
    
    // Test avec un seul élément
    std::vector<int> single_vec;
    single_vec.push_back(42);
    try
    {
        std::vector<int>::iterator it = easyfind(single_vec, 42);
        std::cout << "Un seul élément trouvé: " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test avec doublons
    std::vector<int> dup_vec;
    dup_vec.push_back(5);
    dup_vec.push_back(10);
    dup_vec.push_back(5);
    dup_vec.push_back(15);
    
    try
    {
        std::vector<int>::iterator it = easyfind(dup_vec, 5);
        std::cout << "Première occurrence de 5 à la position: " << std::distance(dup_vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== TESTS DE LA FONCTION EASYFIND ===" << std::endl << std::endl;
    
    testVector();
    testList();
    testDeque();
    testEdgeCases();
    
    std::cout << "=== FIN DES TESTS ===" << std::endl;
    
    return 0;
}
*/