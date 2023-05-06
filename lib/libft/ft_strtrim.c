/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misi-moh <misi-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:17:42 by misi-moh          #+#    #+#             */
/*   Updated: 2023/04/18 15:48:14 by misi-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	char_in_str(char c, char const *s)
{
	while (*s)
	{
		if (c == *s++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*str;

	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (*start && char_in_str(*start, set))
		start++;
	while (start < end && char_in_str(*(end - 1), set))
		end--;
	str = ft_substr(start, 0, end - start);
	return (str);
}
