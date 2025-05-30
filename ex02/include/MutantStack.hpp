/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:56:08 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/30 21:56:58 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    // Types d'itérateurs
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Constructeurs et destructeur (forme canonique)
    MutantStack();
    MutantStack(const MutantStack& other);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack();

    // Fonctions d'itération
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rbegin() const;
    const_reverse_iterator rend() const;
};

// Implémentation du template dans le header

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
{
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
        std::stack<T, Container>::operator=(other);
    }
    return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

// Itérateurs normaux
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}

// Itérateurs inverses
template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
    return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
    return this->c.rend();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
    return this->c.rbegin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
    return this->c.rend();
}

#endif