/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytapano <ytapano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:51:22 by ytapano           #+#    #+#             */
/*   Updated: 2023/11/27 14:02:21 by ytapano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = num_len(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len--] = '\0';
	while (n > 0)
	{
		num[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (num);
}

int	ft_uns_print(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += ft_printchar('0');
	else
	{
		num = ft_uitoa(n);
		len += ft_printstr(num);
		simple_free(num);
	}
	return (len);
}
