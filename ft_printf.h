/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdvarako <kdvarako@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:28:33 by kdvarako          #+#    #+#             */
/*   Updated: 2024/04/04 15:15:58 by kdvarako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
int				ft_c_printf(int ch);
int				ft_s_printf(char *s);
int				ft_p_printf(unsigned long n);
int				ft_d_printf(long n);
int				ft_u_printf(unsigned long n);
int				ft_x_printf(unsigned int n, char ch);
unsigned int	ft_strlen(const char *str);
unsigned long	ft_countdellong(unsigned long n);

#endif