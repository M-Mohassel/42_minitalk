/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:36:24 by misi-moh          #+#    #+#             */
/*   Updated: 2023/05/06 13:20:46 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	formats(va_list args, const char *str)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_puthe_bigx(va_arg(args, unsigned int)));
	else if (*str == 'p')
		return (ft_putpointer(va_arg(args, unsigned long)));
	else if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_putnbr_u(va_arg(args, long long)));
	else if (*str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && fmt++)
			i += formats (args, fmt);
		else
			i += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (i);
}

/*int	main(void)
{
	//ft_printf(" %s ", "Hello World");
	//write (1, "\n",1);
	//printf(" %p ", 0);
	//write (1, "\n",1);
	void	*a;
	unsigned long	b;

	b = LONG_MIN;
	a = &b;
	printf("my printf =  %d\n", ft_printf(" %p %p ", a, a));
	printf("the printf =  %d\n", printf(" %p %p ", a, a));
	return (0);
}*/