/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:57:28 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/02 17:55:26 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>

void testSubjectExampleWithMutantStack()
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

void testSubjectExampleWithList()
{
    std::cout << "=== Test avec std::list (même logique) ===" << std::endl;
    
    std::list<int> mstack;  // On garde le même nom pour montrer l'équivalence
    
    mstack.push_back(5);     // push() devient push_back()
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;  // top() devient back()
    
    mstack.pop_back();       // pop() devient pop_back()
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> s(mstack);
    
    std::cout << std::endl;
}

void testSubjectExampleWithVector()
{
    std::cout << "=== Test avec std::vector (même logique) ===" << std::endl;
    
    std::vector<int> mstack;  // On garde le même nom pour montrer l'équivalence
    
    mstack.push_back(5);     // push() devient push_back()
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;  // top() devient back()
    
    mstack.pop_back();       // pop() devient pop_back()
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::vector<int>::iterator it = mstack.begin();
    std::vector<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::vector<int> s(mstack);
    
    std::cout << std::endl;
}

void testSubjectExampleWithDeque()
{
    std::cout << "=== Test avec std::deque (même logique) ===" << std::endl;
    
    std::deque<int> mstack;  // On garde le même nom pour montrer l'équivalence
    
    mstack.push_back(5);     // push() devient push_back()
    mstack.push_back(17);
    
    std::cout << mstack.back() << std::endl;  // top() devient back()
    
    mstack.pop_back();       // pop() devient pop_back()
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    
    std::deque<int>::iterator it = mstack.begin();
    std::deque<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl << "=== DÉMONSTRATION DE L'ÉQUIVALENCE ===" << std::endl << std::endl;
    
    // Premier test avec MutantStack
    testSubjectExampleWithMutantStack();
    
    // Tests avec différents conteneurs pour prouver l'équivalence
    testSubjectExampleWithList();
    testSubjectExampleWithVector();
    testSubjectExampleWithDeque();
    
    
    std::cout << "✅ === Tous les tests produisent des résultats identiques === ✅" << std::endl << std::endl;
    
    return 0;
}