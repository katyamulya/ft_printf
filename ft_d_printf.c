/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:35:55 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/05 16:19:24 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnum(int n1);

int	ft_d_printf(long n)
{
	int	count;
	int	k;
	int	n1;

	count = 0;
	n1 = (int) n;
	if (n1 == 0)
		return (count = ft_c_printf('0'));
	if (n1 == INT_MAX)
		return (count = ft_s_printf("2147483647"));
	if (n1 == INT_MIN)
		return (count = ft_s_printf("-2147483648"));
	if (n1 < 0)
	{
		count = ft_c_printf('-');
		if (count == -1)
			return (-1);
		n1 = -n1;
	}
	k = ft_printnum(n1);
	if (k == -1)
		return (-1);
	return (count + k);
}

int	ft_printnum(int n1)
{
	unsigned long	k;
	int				count;
	int				fl;

	count = 0;
	fl = 0;
	k = ft_countdellong(n1);
	while (k > 0)
	{
		fl = ft_c_printf((n1 / k) + '0');
		if (fl == -1)
			return (-1);
		count++;
		n1 = n1 - (n1 / k) * k;
		k = k / 10;
	}
	return (count);
}
