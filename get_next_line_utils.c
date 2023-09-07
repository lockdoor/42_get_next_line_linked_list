/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:40:50 by pnamnil           #+#    #+#             */
/*   Updated: 2023/05/13 15:11:41 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// copy stack to tab util \n , replace \n with \0
char	*make_str(t_list **stack, int size, int file)
{
	t_list	*current;
	char	*tab;

	current = *stack;
	while (current)
	{
		if (current->file == file)
			break ;
		current = current->next;
	}
	tab = (char *) malloc (sizeof (char) * (size));
	if (!tab)
		return (NULL);
	while (current && current->item != '\n')
	{
		*tab++ = current->item;
		current = current->next;
	}
	*tab = '\0';
	return (tab - size + 1);
}

t_list	*lstnew(char c, int file)
{
	t_list	*new;

	new = (t_list *) malloc (sizeof (t_list));
	if (c < 0 || c > 127 || !new)
		return (NULL);
	new->file = file;
	new->item = c;
	new->next = NULL;
	return (new);
}

/* return last char of file found in stack or last item instack */
t_list	*last_char_of_file(t_list *lst, int file)
{
	while (lst)
	{
		if (lst->file == file)
			break ;
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->next == NULL || lst->next->file != file)
			break ;
		lst = lst->next;
	}
	return (lst);
}

// should free all stack before return -1
int	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;
	t_list	*file;

	if (!new)
	{
		lstclear (lst);
		return (-1);
	}
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	current = *lst;
	file = last_char_of_file (current, new->file);
	current = file->next;
	file->next = new;
	new->next = current;
	return (0);
}

/* clear all stack when error occur */
void	lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*prev;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		prev = current;
		current = current->next;
		free (prev);
	}
	*lst = NULL;
}
