/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:25:28 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/18 15:47:40 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*a;

	l = ft_strlen(s);
	a = malloc ((l + 1) * sizeof(char));
	if (!a)
		return (NULL);
	ft_strlcpy(a, s, l + 1);
	return (a);
}
