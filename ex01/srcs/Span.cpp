/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:53:15 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/30 21:54:00 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

// Constructeur
Span::Span(unsigned int N) : _maxSize(N)
{
    _numbers.reserve(N);
}

// Constructeur de copie
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

// Opérateur d'assignation
Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// Destructeur
Span::~Span()
{
}

// Ajouter un nombre
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw SpanFullException();
    
    _numbers.push_back(number);
}

// Trouver la plus petite distance
unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    // Créer une copie et la trier pour faciliter la recherche
    std::vector<int> sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    
    unsigned int min_span = UINT_MAX;
    
    // La plus petite différence sera toujours entre deux éléments adjacents dans un tableau trié
    for (size_t i = 1; i < sorted_numbers.size(); ++i)
    {
        unsigned int current_span = static_cast<unsigned int>(sorted_numbers[i] - sorted_numbers[i - 1]);
        if (current_span < min_span)
            min_span = current_span;
    }
    
    return min_span;
}

// Trouver la plus grande distance
unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    // Utiliser les algorithmes STL pour trouver min et max
    std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(*max_it - *min_it);
}

// Fonctions utilitaires
unsigned int Span::size() const
{
    return _numbers.size();
}

unsigned int Span::maxSize() const
{
    return _maxSize;
}

bool Span::isFull() const
{
    return _numbers.size() >= _maxSize;
}

bool Span::isEmpty() const
{
    return _numbers.empty();
}

// Implémentation des exceptions
const char* Span::SpanFullException::what() const throw()
{
    return "Span is full: cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No span can be found: need at least 2 numbers";
}