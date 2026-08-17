/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:51:29 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/10 14:31:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!str || !substr) && len == 0)
		return (NULL);
	if (*substr == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == substr[j])
		{
			while (substr[j] && substr[j] == str[i + j] && (i + j) < len)
				j++;
			if (substr[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
