/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:52:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/01 18:57:08 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Forme canonique
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    
    Span& operator=(const Span& other);

    // Fonctions demandées par le sujet
    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    int shortestSpan();
    int longestSpan();
};

#endif