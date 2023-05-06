/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:54:28 by misi-moh          #+#    #+#             */
/*   Updated: 2023/05/06 13:20:53 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		i++;
		str++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	sign;
	int	c;
	int	i;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		i += ft_putchar('-');
		sign = -1;
	}
	if (n / 10)
		i += ft_putnbr(n / 10 * sign);
	c = '0' + n % 10 * sign;
	i += ft_putchar(c);
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	c;
	int				sign;
	int				i;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		i += ft_putchar('-');
		sign = -1;
	}
	if (n / 10)
		i += ft_putnbr_u(n / 10 * sign);
	c = '0' + n % 10 * sign;
	i += ft_putchar(c);
	return (i);
}
