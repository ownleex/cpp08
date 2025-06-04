/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:52:53 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/05 00:57:34 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "=== Test de base du sujet ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Valeurs ajoutées : 6 3 17 9 11" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Test avec 20000 nombres ===" << std::endl;
    {
        Span sp(20000);
        
        // Remplir avec des nombres aléatoires
        for (int i = 0; i < 20000; ++i) {
            sp.addNumber(i * 5);
        }
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Test avec plage d'itérateurs ===" << std::endl;
    {
        std::vector<int> vec;
        for (int i = 0; i < 100; ++i) {
            vec.push_back(i * 5); // on remplit de 5 à 500
        }
        
        Span sp(100);
        sp.addNumbers(vec.begin(), vec.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    
    std::cout << "\n=== Test avec exceptions ===" << std::endl;
    {
        Span sp(3);
        
        // Test avec 0 éléments
        try {
            std::cout << sp.shortestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "Exception 0 élément: " << e.what() << std::endl;
        }
        
        // Test avec 1 élément
        sp.addNumber(42);
        try {
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "Exception 1 élément: " << e.what() << std::endl;
        }
        
        // Test span plein
        sp.addNumber(10);
        sp.addNumber(20);
        try {
            sp.addNumber(30);
        }
        catch (std::exception& e) {
            std::cout << "Exception span plein: " << e.what() << std::endl;
        }
    }
    
    return 0;
}