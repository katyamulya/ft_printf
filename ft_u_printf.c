/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:36:18 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/05 16:23:29 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_printf(unsigned long n)
{
	int				count;
	unsigned long	k;
	int				fl;

	count = 0;
	fl = 0;
	if (n == 0)
		return (count = ft_c_printf('0'));
	if (n >= UINT_MAX)
		return (count = ft_s_printf("4294967295"));
	k = ft_countdellong(n);
	while (k > 0)
	{
		fl = ft_c_printf((n / k) + '0');
		if (fl == -1)
			return (-1);
		count++;
		n = n - (n / k) * k;
		k = k / 10;
	}
	return (count);
}
