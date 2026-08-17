/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diatisin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:31:01 by diatisin          #+#    #+#             */
/*   Updated: 2026/05/21 12:22:16 by diatisin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*int main()
{
	size_t i;


	ft_bzero(str, 5);
	i = 0;
		while (i < 10)
	{
		printf("str[%zu] = %d\n", i, (unsigned char)str[i]);
		i++;
	}
	return (0);
}*/
