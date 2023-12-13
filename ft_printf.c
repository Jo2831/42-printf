/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:51:15 by ytapano           #+#    #+#             */
/*   Updated: 2023/11/29 12:55:20 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list info, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar(va_arg(info, int));
	else if (format == 's')
		len += ft_printstr(va_arg(info, const char *));
	else if (format == 'd' || format == 'i')
		len += ft_printnbr(va_arg(info, int));
	else if (format == 'u')
		len += ft_uns_print(va_arg(info, unsigned int));
	else if (format == 'p')
		len += ft_ptr_print(va_arg(info, void *));
	else if (format == 'x' || format == 'X')
		len += ft_hex_print(va_arg(info, unsigned int), format);
	else if (format == '%')
		len += ft_printpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	info;
	int		x;
	int		len;

	x = -1;
	len = 0;
	va_start(info, str);
	while (str[++x] != '\0')
	{
		if (str[x] == '%')
			len += ft_formats(info, str[++x]);
		else
			len += ft_printchar(str[x]);
	}
	va_end(info);
	return (len);
}
//  int main()
//  {
// 	ft_printf("%p", 7873835);
// 	printf("%p", 7873835);
// 	return (0);
//  }