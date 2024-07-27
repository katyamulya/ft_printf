/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:34:52 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/05 14:59:10 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_printf(char *s)
{
	int	fl;
	int	i;

	i = 0;
	fl = 0;
	if (s == NULL)
		return (ft_s_printf("(null)"));
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] != '\0')
	{
		fl = ft_c_printf(s[i]);
		if (fl == -1)
			return (-1);
		i++;
	}
	return (i);
}
