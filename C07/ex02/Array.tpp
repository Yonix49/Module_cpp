/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:32:51 by mhajji-b          #+#    #+#             */
/*   Updated: 2023/10/14 09:36:59 by mhajji-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
Array<T>::Array()
{
	this->n = 0;
	this->array = new T[this->n];
}

template <typename T>
Array<T>::Array(unsigned int n, T *array)
{
	this->n = n;
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
	{
		this->array[i] = array[i];
	}
}
template <typename T>
Array<T>::Array(unsigned int n)
{
	this->n = n;
	this->array = new T[this->n];

}

template <typename T>
Array<T>::~Array() 
{
	delete[] this->array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &src) 
{
	if (this != &src)
	{
		delete[] this->array;
		this->n = src.n;
		this->array = new T[this->n];
		for (unsigned int i = 0; i < this->n; i++)
		{
			this->array[i] = src.array[i];
		}
	}
	return *this; // Pas de & avant *this
}

template <typename T>
Array<T>::Array(const Array<T> &src) 
{
	this->n = src.n;
	this->array = new T[this->n];
	for (unsigned int i = 0; i < this->n; i++)
	{
		this->array[i] = src.array[i];
	}
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= n)
    {
        throw Error(index);
    }
    return array[index];
}

template <typename T>
unsigned int Array<T>::Size() const
{
	return this->n;
}
