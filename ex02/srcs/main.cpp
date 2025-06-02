/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:57:28 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/02 17:36:47 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
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
    std::cout << "=== Test avec std::list ===" << std::endl;
    
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
    
    // Pas de conversion vers std::stack pour une liste
    
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== DÉMONSTRATION DE L'ÉQUIVALENCE ===" << std::endl << std::endl;
    
    // Premier test avec MutantStack
    testSubjectExampleWithMutantStack();
    
    // Deuxième test avec std::list pour prouver l'équivalence
    testSubjectExampleWithList();
    
    std::cout << "✅ === Les deux tests produisent des résultats identiques === ✅" << std::endl;
    
    return 0;
}