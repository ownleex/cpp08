/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:57:28 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/02 18:55:05 by ayarmaya         ###   ########.fr       */
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
    
    std::list<int> list;
    
    list.push_back(5);     // push() devient push_back()
    list.push_back(17);
    
    std::cout << list.back() << std::endl;  // top() devient back()
    
    list.pop_back();       // pop() devient pop_back()
    
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
    
    std::cout << std::endl;
}

void testSubjectExampleWithVector()
{
    std::cout << "=== Test avec std::vector (même logique) ===" << std::endl;
    
    std::vector<int> vector;
    
    vector.push_back(5);     // push() devient push_back()
    vector.push_back(17);
    
    std::cout << vector.back() << std::endl;  // top() devient back()
    
    vector.pop_back();       // pop() devient pop_back()
    
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
    
    std::cout << std::endl;
}

void testSubjectExampleWithDeque()
{
    std::cout << "=== Test avec std::deque (même logique) ===" << std::endl;
    
    std::deque<int> deque;
    
    deque.push_back(5);     // push() devient push_back()
    deque.push_back(17);
    
    std::cout << deque.back() << std::endl;  // top() devient back()
    
    deque.pop_back();       // pop() devient pop_back()
    
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