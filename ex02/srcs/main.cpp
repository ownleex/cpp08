/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:57:28 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/30 21:57:32 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void testSubjectExample()
{
    std::cout << "=== Test de l'exemple du sujet ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Contenu avec itérateurs:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Conversion vers std::stack
    std::stack<int> s(mstack);
    std::cout << "Conversion vers std::stack réussie, size: " << s.size() << std::endl;
    
    std::cout << std::endl;
}

void testWithList()
{
    std::cout << "=== Comparaison avec std::list ===" << std::endl;
    
    // Test avec MutantStack
    std::cout << "Avec MutantStack:" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test avec std::list pour comparaison
    std::cout << "Avec std::list (même données):" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testReverseIterators()
{
    std::cout << "=== Test des itérateurs inverses ===" << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i)
    {
        mstack.push(i * 10);
    }
    
    std::cout << "Ordre normal: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Ordre inverse: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testConstIterators()
{
    std::cout << "=== Test des itérateurs const ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(100);
    mstack.push(200);
    mstack.push(300);
    
    const MutantStack<int> const_mstack = mstack;
    
    std::cout << "Avec itérateurs const: ";
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Avec itérateurs const inverses: ";
    for (MutantStack<int>::const_reverse_iterator it = const_mstack.rbegin(); it != const_mstack.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testCopyAndAssignment()
{
    std::cout << "=== Test de copie et assignation ===" << std::endl;
    
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    
    // Test constructeur de copie
    MutantStack<int> copy(original);
    std::cout << "Copie: ";
    for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test opérateur d'assignation
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "Assigné: ";
    for (MutantStack<int>::iterator it = assigned.begin(); it != assigned.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testSTLAlgorithms()
{
    std::cout << "=== Test avec algorithmes STL ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(30);
    mstack.push(10);
    mstack.push(50);
    mstack.push(20);
    mstack.push(40);
    
    std::cout << "Avant tri: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Utiliser std::sort
    std::sort(mstack.begin(), mstack.end());
    
    std::cout << "Après tri: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Chercher un élément
    MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 30);
    if (found != mstack.end())
    {
        std::cout << "Élément 30 trouvé à la position: " << std::distance(mstack.begin(), found) << std::endl;
    }
    
    std::cout << std::endl;
}

void testDifferentContainers()
{
    std::cout << "=== Test avec différents conteneurs sous-jacents ===" << std::endl;
    
    // Test avec std::vector comme conteneur sous-jacent
    MutantStack<int, std::vector<int> > vstack;
    vstack.push(1);
    vstack.push(2);
    vstack.push(3);
    
    std::cout << "MutantStack avec std::vector: ";
    for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test avec std::deque (par défaut)
    MutantStack<int> dstack;
    dstack.push(10);
    dstack.push(20);
    dstack.push(30);
    
    std::cout << "MutantStack avec std::deque: ";
    for (MutantStack<int>::iterator it = dstack.begin(); it != dstack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
}

void testStackFunctionality()
{
    std::cout << "=== Test des fonctionnalités de stack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    std::cout << "Stack vide: " << (mstack.empty() ? "Oui" : "Non") << std::endl;
    std::cout << "Taille: " << mstack.size() << std::endl;
    
    mstack.push(42);
    mstack.push(84);
    
    std::cout << "Après ajout de 2 éléments:" << std::endl;
    std::cout << "Stack vide: " << (mstack.empty() ? "Oui" : "Non") << std::endl;
    std::cout << "Taille: " << mstack.size() << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Après pop:" << std::endl;
    std::cout << "Taille: " << mstack.size() << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== TESTS DE LA CLASSE MUTANTSTACK ===" << std::endl << std::endl;
    
    testSubjectExample();
    testWithList();
    testReverseIterators();
    testConstIterators();
    testCopyAndAssignment();
    testSTLAlgorithms();
    testDifferentContainers();
    testStackFunctionality();
    
    std::cout << "=== FIN DES TESTS ===" << std::endl;
    
    return 0;
}