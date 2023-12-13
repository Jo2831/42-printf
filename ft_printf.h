/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:51:26 by ytapano           #+#    #+#             */
/*   Updated: 2023/11/27 17:40:33 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_hex_len(unsigned int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hex_print(unsigned int num, const char format);
int		ft_formats(va_list info, const char format);
void	ft_putstr(const char *str);
void	simple_free(void *ptr);
int		ft_printstr(const char *str);
int		ft_printchar(int c);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_uns_print(unsigned int n);
int		ft_ptr_len(unsigned long long num);
void	ft_put_ptr(size_t num);
int		ft_ptr_print(void *ptr);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);

#endif
