/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viktoria <viktoria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:29 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/13 19:41:40 by viktoria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
class Array
{
private:
  unsigned int _n;
  T *_array;

public:
  Array();
  Array(unsigned int &n);
  Array(const Array<T> &o);
  Array<T> &operator=(const Array<T> &o);
  ~Array();

  unsigned int size() const;
  T &operator[](unsigned int index);
};