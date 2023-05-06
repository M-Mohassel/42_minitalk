/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:37:07 by misi-moh          #+#    #+#             */
/*   Updated: 2023/05/06 13:21:50 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putpointer(unsigned long x)
{
	char	*a;
	int		i;

	i = 0;
	a = "0123456789abcdef";
	if (!x)
		return (ft_putstr("(nil)"));
	if (x / 16)
		i += ft_putpointer(x / 16);
	else
		i += ft_putstr("0x");
	i += ft_putchar(a[x % 16]);
	return (i);
}

int	ft_puthe_bigx(unsigned long x)
{
	char	*a;
	int		i;

	i = 0;
	a = "0123456789ABCDEF";
	if (x / 16)
		i += ft_puthe_bigx(x / 16);
	i += ft_putchar(a[x % 16]);
	return (i);
}

int	ft_puthex(unsigned long x)
{
	char	*a;
	int		i;

	i = 0;
	a = "0123456789abcdef";
	if (x / 16)
		i += ft_puthex(x / 16);
	i += ft_putchar(a[x % 16]);
	return (i);
}
