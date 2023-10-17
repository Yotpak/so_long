/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalci <tbalci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:57:59 by tbalci            #+#    #+#             */
/*   Updated: 2023/08/02 23:50:35 by tbalci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_type(char c, va_list arg);
int	ft_printf(const char *sign, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_unsignedputnbr(unsigned int n);
int	ft_hex(char c, unsigned int w);
int	ft_p(unsigned long int n);
int	ft_putnbr_i(int n);

#endif
