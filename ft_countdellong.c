/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdellong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:15:06 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/04 15:15:20 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_countdellong(unsigned long n)
{
	unsigned long	k;

	k = 1;
	while (n > 0)
	{
		n = n / 10;
		k = k * 10;
	}
	return (k / 10);
}
