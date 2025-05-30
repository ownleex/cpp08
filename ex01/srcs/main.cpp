/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:52:53 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/30 21:54:08 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

void testBasicExample()
{
    std::cout << "=== Test de l'exemple du sujet ===" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testExceptions()
{
    std::cout << "=== Test des exceptions ===" << std::endl;
    
    Span sp(3);
    
    // Test NoSpanException avec 0 éléments
    try
    {
        sp.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception attendue (0 éléments): " << e.what() << std::endl;
    }
    
    // Test NoSpanException avec 1 élément
    sp.addNumber(42);
    try
    {
        sp.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception attendue (1 élément): " << e.what() << std::endl;
    }
    
    // Test SpanFullException
    sp.addNumber(10);
    sp.addNumber(20);
    try
    {
        sp.addNumber(30); // Devrait réussir
        sp.addNumber(40); // Devrait échouer
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception attendue (span plein): " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testLargeSpan()
{
    std::cout << "=== Test avec 10,000 nombres ===" << std::endl;
    
    const unsigned int SIZE = 10000;
    Span sp(SIZE);
    
    // Initialiser le générateur de nombres aléatoires
    std::srand(std::time(0));
    
    std::cout << "Ajout de " << SIZE << " nombres aléatoires..." << std::endl;
    
    // Ajouter des nombres un par un
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        sp.addNumber(std::rand() % 100000); // Nombres entre 0 et 99999
    }
    
    std::cout << "Taille finale: " << sp.size() << "/" << sp.maxSize() << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;
}

void testIteratorRange()
{
    std::cout << "=== Test avec plage d'itérateurs ===" << std::endl;
    
    // Test avec std::vector
    std::vector<int> vec;
    for (int i = 0; i < 1000; ++i)
    {
        vec.push_back(i * 2); // Nombres pairs de 0 à 1998
    }
    
    Span sp1(1000);
    try
    {
        sp1.addNumbers(vec.begin(), vec.end());
        std::cout << "Ajouté " << sp1.size() << " nombres depuis un vector" << std::endl;
        std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test avec std::list
    std::list<int> lst;
    for (int i = 100; i >= 1; --i)
    {
        lst.push_back(i);
    }
    
    Span sp2(100);
    try
    {
        sp2.addNumbers(lst.begin(), lst.end());
        std::cout << "Ajouté " << sp2.size() << " nombres depuis une list" << std::endl;
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Erreur: " << e.what() << std::endl;
    }
    
    // Test d'exception avec trop d'éléments
    Span sp3(50);
    try
    {
        sp3.addNumbers(vec.begin(), vec.end()); // Trop d'éléments
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception attendue (trop d'éléments): " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

void testEdgeCases()
{
    std::cout << "=== Tests de cas limites ===" << std::endl;
    
    // Test avec des nombres négatifs
    Span sp1(5);
    sp1.addNumber(-10);
    sp1.addNumber(-5);
    sp1.addNumber(0);
    sp1.addNumber(5);
    sp1.addNumber(10);
    
    std::cout << "Avec nombres négatifs:" << std::endl;
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
    
    // Test avec des doublons
    Span sp2(4);
    sp2.addNumber(5);
    sp2.addNumber(5);
    sp2.addNumber(10);
    sp2.addNumber(10);
    
    std::cout << "Avec doublons:" << std::endl;
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
    
    // Test avec seulement 2 nombres
    Span sp3(2);
    sp3.addNumber(1);
    sp3.addNumber(100);
    
    std::cout << "Avec 2 nombres seulement:" << std::endl;
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    
    std::cout << std::endl;
}

void testCopyAndAssignment()
{
    std::cout << "=== Test de copie et assignation ===" << std::endl;
    
    Span sp1(5);
    sp1.addNumber(1);
    sp1.addNumber(10);
    sp1.addNumber(100);
    
    // Test constructeur de copie
    Span sp2(sp1);
    std::cout << "Copie - Taille: " << sp2.size() << ", Longest span: " << sp2.longestSpan() << std::endl;
    
    // Test opérateur d'assignation
    Span sp3(10);
    sp3 = sp1;
    std::cout << "Assignation - Taille: " << sp3.size() << ", Longest span: " << sp3.longestSpan() << std::endl;
    
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== TESTS DE LA CLASSE SPAN ===" << std::endl << std::endl;
    
    testBasicExample();
    testExceptions();
    testLargeSpan();
    testIteratorRange();
    testEdgeCases();
    testCopyAndAssignment();
    
    std::cout << "=== FIN DES TESTS ===" << std::endl;
    
    return 0;
}