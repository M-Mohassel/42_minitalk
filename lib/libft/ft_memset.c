/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:29:46 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/18 15:47:01 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;
	size_t	i;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = c;
		i++;
	}
	return (a);
}
