/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:53:15 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/03 01:46:36 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("❌ Span est plein ❌");
    
    _numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("❌ pas assez de nombre ❌");
    
    // Copier et trier le vecteur
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    // Trouver la plus petite différence entre deux nombres adjacents
    int minSpan = std::numeric_limits<int>::max();
    std::vector<int>::iterator it = sorted.begin();
    std::vector<int>::iterator next = it + 1;
    
    while (next != sorted.end())
    {
        int span = *next - *it;
        if (span < minSpan)
            minSpan = span;
        ++it;
        ++next;
    }
    
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("❌ pas assez de nombre ❌");
    
    // Utiliser les algorithmes STL pour trouver min et max
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return max - min;
}
