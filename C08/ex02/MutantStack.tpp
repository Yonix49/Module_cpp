/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/14 09:36:59 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
}

template <typename T>
MutantStack<T>::~MutantStack() {
}


template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &src) {
    if (this != &src) {
        std::stack<T>::operator=(src); // Utilisez l'opérateur d'assignation de la classe de base pour copier les éléments.
    }
    return *this;
}
