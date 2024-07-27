/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:35:33 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/05 16:03:59 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getstr_l(char *s, int i, unsigned long n);

int	ft_p_printf(unsigned long n)
{
	int				count;
	unsigned long	n1;
	int				i;
	char			*s;

	count = 0;
	s = NULL;
	if (n == 0)
		return (ft_s_printf("0x0"));
	i = 0;
	n1 = n;
	while (n1 != 0)
	{
		n1 = n1 / 16;
		i++;
	}
	count = ft_getstr_l(s, (i - 1), n);
	return (count);
}

int	ft_getstr_l(char *s, int i, unsigned long n)
{
	int		count;
	int		fl;

	fl = 0;
	s = (char *)calloc((i + 2), sizeof(char));
	if (!s)
		return (-1);
	while (n != 0)
	{
		if ((n % 16) < 10)
			s[i] = (n % 16) + 48;
		else
			s[i] = (n % 16) - 10 + 'a';
		n = n / 16;
		i--;
	}
	count = ft_s_printf("0x");
	if (count == -1)
		return (-1);
	fl = ft_s_printf(s);
	if (fl == -1)
		return (-1);
	free (s);
	return (count + fl);
}
