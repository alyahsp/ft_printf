/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:17:23 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/05 16:24:52 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*cpy;

	cpy = ft_memalloc(content_size);
	if (!(cpy))
		return (NULL);
	if (!content)
	{
		cpy = NULL;
		content_size = 0;
	}
	else
		cpy = ft_memcpy(cpy, content, content_size);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = cpy;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
