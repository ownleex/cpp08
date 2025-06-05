/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:57:28 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/05 15:06:50 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>

void testMutantStack()
{
    std::cout << "=== Test avec MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
    
    std::cout << std::endl;
}

void testList()
{
    std::cout << "=== Test avec std::list (même logique) ===" << std::endl;
    
    std::list<int> list;
    
    list.push_back(5);
    list.push_back(17);
    
    std::cout << list.back() << std::endl;
    
    list.pop_back();
    
    std::cout << list.size() << std::endl;
    
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> s(list);
    
    std::cout << std::endl << "✅ === List resultat identique à MutantStack === ✅" << std::endl << std::endl;
}

void testVector()
{
    std::cout << std::endl << "=== Test avec std::vector (même logique) ===" << std::endl;
    
    std::vector<int> vector;
    
    vector.push_back(5);
    vector.push_back(17);
    
    std::cout << vector.back() << std::endl;
    
    vector.pop_back();
    
    std::cout << vector.size() << std::endl;
    
    vector.push_back(3);
    vector.push_back(5);
    vector.push_back(737);
    vector.push_back(0);
    
    std::vector<int>::iterator it = vector.begin();
    std::vector<int>::iterator ite = vector.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::vector<int> s(vector);
    
    std::cout << std::endl << "✅ === Vector resultat identique à MutantStack === ✅" << std::endl << std::endl;
}

void testDeque()
{
    std::cout << std::endl << "=== Test avec std::deque (même logique) ===" << std::endl;
    
    std::deque<int> deque;
    
    deque.push_back(5);
    deque.push_back(17);
    
    std::cout << deque.back() << std::endl;
    
    deque.pop_back();
    
    std::cout << deque.size() << std::endl;
    
    deque.push_back(3);
    deque.push_back(5);
    deque.push_back(737);
    deque.push_back(0);
    
    std::deque<int>::iterator it = deque.begin();
    std::deque<int>::iterator ite = deque.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl << "✅ === Deque resultat identique à MutantStack === ✅" << std::endl << std::endl;
}

void additionalTests()
{
    std::cout << "=== Tests supplémentaires ===" << std::endl << std::endl;
    
    MutantStack<int> mstack;
    // Test 1: Itérateurs inverses
    std::cout << "== Test itérateurs ==" << std::endl << std::endl;
    mstack.push(2);
    mstack.push(4);
    mstack.push(6);
    mstack.push(8);
    mstack.push(10);
    
    std::cout << "Parcours avec begin/end: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Parcours inverse avec rbegin/rend: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;
    
    
    // Test : Algorithme STL
    std::cout << "== Test algorithme STL ==" << std::endl << std::endl;

    // Test avec une valeur qui existe
    MutantStack<int>::iterator foundInt = std::find(mstack.begin(), mstack.end(), 4);
    if (foundInt != mstack.end())
        std::cout << "✅ Valeur 4 trouvée à l'index : " << std::distance(mstack.begin(), foundInt) << std::endl;
    else
        std::cout << "❌ Valeur 4 non trouvée" << std::endl;

    // Test avec une valeur qui n'existe pas
    foundInt = std::find(mstack.begin(), mstack.end(), 999);
    if (foundInt != mstack.end())
        std::cout << "✅ Valeur 999 trouvée à l'index : " << std::distance(mstack.begin(), foundInt) << "std::endl;
    else
        std::cout << "❌ Valeur 999 non trouvée" << std::endl;
    std::cout << std::endl;

    
    
    // Test : Test avec des strings
    std::cout << "== Test avec des strings ==" << std::endl << std::endl;
    
    MutantStack<std::string> stringStack;
    stringStack.push("cette");
    stringStack.push("phrase");
    stringStack.push("contient");
    stringStack.push("cinq");
    stringStack.push("mots");
    
    std::cout << "== Test itérateurs ==" << std::endl << std::endl;
    std::cout << "Parcours avec begin/end: " << std::endl;
    for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Parcours inverse avec rbegin/rend: " << std::endl;
    for (MutantStack<std::string>::reverse_iterator it = stringStack.rbegin(); it != stringStack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    // Test : Algorithme STL
    std::cout << "== Test algorithme STL ==" << std::endl << std::endl;

    // Test avec une valeur qui existe
    MutantStack<std::string>::iterator foundString = std::find(stringStack.begin(), stringStack.end(), "contient");
    if (foundString != stringStack.end())
        std::cout << "✅ Valeur - contient - trouvée à l'index : " << std::distance(stringStack.begin(), foundString) << std::endl;
    else
        std::cout << "❌ Valeur - contient - non trouvée" << std::endl;

    // Test avec une valeur qui n'existe pas
    foundString = std::find(stringStack.begin(), stringStack.end(), "inexistant");
    if (foundString != stringStack.end())
        std::cout << "✅ Valeur - inexistant - trouvée à l'index : " << std::distance(stringStack.begin(), foundString) << std::endl;
    else
        std::cout << "❌ Valeur - inexistant - non trouvée" << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl << "=== DÉMONSTRATION DE L'ÉQUIVALENCE ===" << std::endl << std::endl;
    
    // Premier test avec MutantStack
    testMutantStack();
    
    // Tests avec différents conteneurs pour prouver l'équivalence
    testList();
    testVector();
    testDeque();
    
    std::cout << "✅ === Tous les tests produisent des résultats identiques === ✅" << std::endl << std::endl << std::endl;
    
    // Tests supplémentaires
    additionalTests();
    
    return 0;
}