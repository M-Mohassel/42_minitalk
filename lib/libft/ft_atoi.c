/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:45:09 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/18 15:32:37 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	final_num;

	i = 0;
	s = 1;
	final_num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final_num *= 10;
		final_num = final_num + str[i] - '0';
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			break ;
	}
	return (final_num * s);
}
