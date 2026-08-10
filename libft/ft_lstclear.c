/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:45:49 by diatisin          #+#    #+#             */
/*   Updated: 2026/08/10 14:30:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (lst && del)
	{
		curr = *lst;
		while (curr)
		{
			temp = curr->next;
			del(curr->content);
			free(curr);
			curr = temp;
		}
		*lst = NULL;
	}
}
