/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:36:41 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/04 15:05:00 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getstr(char *s, int i, unsigned int n, char ch);

int	ft_x_printf(unsigned int n, char ch)
{
	int				count;
	unsigned int	n1;
	int				i;
	char			*s;

	count = 0;
	if (n == 0)
	{
		count = ft_c_printf('0');
		return (count);
	}
	i = 0;
	n1 = n;
	while (n1 != 0)
	{
		n1 = n1 / 16;
		i++;
	}
	s = (char *)calloc((i + 1), sizeof(char));
	if (!s)
		return (-1);
	ft_getstr(s, (i - 1), n, ch);
	count = ft_s_printf(s);
	free (s);
	return (count);
}

void	ft_getstr(char *s, int i, unsigned int n, char ch)
{
	while (n != 0)
	{
		if ((n % 16) < 10)
			s[i] = (n % 16) + 48;
		else
		{
			if (ch == 'x')
				s[i] = (n % 16) - 10 + 'a';
			else
				s[i] = (n % 16) - 10 + 'A';
		}
		n = n / 16;
		i--;
	}
}
