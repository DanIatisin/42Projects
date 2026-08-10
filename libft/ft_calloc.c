/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:44:51 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/10 14:32:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	sum;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > ((size_t)-1) / size)
		return (NULL);
	sum = nmemb * size;
	ptr = malloc(sum);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, sum);
	return (ptr);
}
