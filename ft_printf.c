/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:54:21 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/05 12:54:38 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_findformat(const char *format, va_list a_list);
int	ft_ifspecifier(const char ch);
int	ft_output(va_list a_list, const char ch);

int	ft_printf(const char *format, ...)
{
	va_list	a_list;
	int		count;

	va_start(a_list, format);
	count = 0;
	count = ft_findformat(format, a_list);
	va_end(a_list);
	return (count);
}

int	ft_findformat(const char *format, va_list a_list)
{
	int		i;
	int		count;
	int		fl;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		fl = 0;
		if (format[i] == '%' && format[i + 1] != '\0' \
		&& ft_ifspecifier(format[i + 1]) == 1)
		{
			fl = ft_output(a_list, format[i + 1]);
			i++;
		}
		else
			fl = ft_c_printf(format[i]);
		if (fl > 0)
			count += fl;
		if (fl < 0)
			return (-1);
		i++;
	}
	return (count);
}

int	ft_ifspecifier(const char ch)
{
	const char	*specifiers;
	int			i;

	specifiers = "cspdiuxX%%";
	i = 0;
	while (specifiers[i] != '\0')
	{
		if (ch == specifiers[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_output(va_list a_list, const char ch)
{
	if (ch == 'c')
		return (ft_c_printf(va_arg(a_list, int)));
	if (ch == 's')
		return (ft_s_printf(va_arg(a_list, char *)));
	if (ch == 'p')
		return (ft_p_printf(va_arg(a_list, unsigned long)));
	if (ch == 'd')
		return (ft_d_printf(va_arg(a_list, long)));
	if (ch == 'i')
		return (ft_d_printf(va_arg(a_list, long)));
	if (ch == 'u')
		return (ft_u_printf(va_arg(a_list, unsigned int)));
	if (ch == 'x')
		return (ft_x_printf(va_arg(a_list, unsigned int), 'x'));
	if (ch == 'X')
		return (ft_x_printf(va_arg(a_list, unsigned int), 'X'));
	if (ch == '%')
		return (ft_c_printf('%'));
	return (0);
}
