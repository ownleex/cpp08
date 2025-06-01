/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 23:07:58 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/06/01 23:14:16 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

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