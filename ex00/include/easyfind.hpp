/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:09:19 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/30 21:27:17 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    
    return it;
}

template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    
    return it;
}

#endif