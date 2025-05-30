/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:52:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/30 21:53:50 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Constructeur et destructeur
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Fonctions membres
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Fonction pour ajouter une plage d'itérateurs
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    // Fonctions utilitaires
    unsigned int size() const;
    unsigned int maxSize() const;
    bool isFull() const;
    bool isEmpty() const;
    
    // Exceptions
    class SpanFullException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    
    class NoSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

// Implémentation du template dans le header
template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
    // Calculer la distance pour vérifier si on peut ajouter tous les éléments
    typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
    
    if (_numbers.size() + static_cast<unsigned int>(distance) > _maxSize)
        throw SpanFullException();
    
    // Utiliser l'algorithme STL pour insérer
    _numbers.insert(_numbers.end(), begin, end);
}

#endif