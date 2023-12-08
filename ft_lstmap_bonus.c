/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:16:35 by smarin-a          #+#    #+#             */
/*   Updated: 2023/10/16 15:27:19 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_wrapper(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_list;
	void	*v;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		v = f(lst->content);
		next_list = ft_lstnew(v);
		if (next_list == NULL)
		{
			del (v);
			ft_lstclear(&new_list, del_wrapper);
			return (NULL);
		}
		ft_lstadd_back(&new_list, next_list);
		lst = lst->next;
	}
	return (new_list);
}
