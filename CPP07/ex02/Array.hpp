/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuznets <vkuznets@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:50:29 by vkuznets          #+#    #+#             */
/*   Updated: 2025/02/12 13:08:03 by vkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T> class Array
{
  private:
    unsigned int _n;
    T *_array;

  public:
    Array();
    Array(unsifned int &n);
    Array(const Array<T> &o);
    Array<T> &operator=(const Array<T> &o);
    ~Array();

    unsigned int size() const;
    T &operator[](unsigned int index);
};