/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:51:18 by ytapano           #+#    #+#             */
/*   Updated: 2023/11/29 12:56:17 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_ptr(size_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_ptr_print(void *ptr)
{
	int					len;
	unsigned long long	num;

	num = (unsigned long long)ptr;
	len = 0;
	len += ft_printstr("0x");
	// if (num == 0)
	// 	len += write(1, "0", 1);
	{
		ft_put_ptr(num);
		len += ft_ptr_len(num);
	}
	return (len);
}
