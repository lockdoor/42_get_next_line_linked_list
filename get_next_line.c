/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:40:50 by pnamnil           #+#    #+#             */
/*   Updated: 2023/05/13 15:11:41 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* print stack of file
void	print_stack(t_list *stack, int file)
{
	while (stack)
	{
		if (stack->file == file)
			break ;
		stack = stack->next;
	}
	if (stack)
		printf ("\nfile %d: ", file);
	while (stack)
	{
		printf ("%c", stack->item);
		if (stack->next == NULL || stack->next->file != file)
			break;
		stack = stack->next;
	}
}
*/

/* 
** create buffer size is BUFFER_SIZE
** read file n time and add buffer to stack
** bf[i] is ascii and not '\0'
** check b[i]: printf ("char: %c\tint: %d\n", bf[i], bf[i]);
** every time add buffer to stack then set zero to bf[i]
** find '\n' from stack, if found break this read file
** when exited read (found '\n' from stack) or read = 0
** if error found should test print_stack
** make str add to line then free str from stack
*/
int	get_next_line(int fd, char **line)
{
	static t_list	*stack;
	char			bf[BUFFER_SIZE];
	int				i;
	int				nbyte;

	while (read (fd, bf, BUFFER_SIZE))
	{
		i = -1;
		while (++i < BUFFER_SIZE && bf[i] > 0 && bf [i] <= 127)
		{
			if (lstadd_back(&stack, lstnew(bf[i], fd)) == -1)
				return (-1);
			bf[i] = '\0';
		}
		if (find_new_line (stack, fd))
			break ;
	}
	nbyte = find_new_line (stack, fd);
	if (nbyte)
	{
		*line = make_str (&stack, nbyte, fd);
		pop_stack (&stack, fd);
		return (1);
	}
	return (0);
}

/* garantee stack->file == file */
t_list	*pop_stack2(t_list *stack)
{
	t_list	*prev;

	while (stack && stack->item != '\n')
	{
		prev = stack;
		stack = stack->next;
		free (prev);
	}
	if (stack && stack->item == '\n')
	{
		prev = stack;
		stack = stack->next;
		free (prev);
	}
	return (stack);
}

/* free stack until '\n' and set new stack point */
void	pop_stack(t_list **lst, int file)
{
	t_list	*stack;
	t_list	*before_file;

	stack = *lst;
	before_file = NULL;
	while (stack)
	{
		if (stack->file == file)
			break ;
		if (stack->next->file == file)
		{
			before_file = stack;
			stack = stack->next;
			break ;
		}
		stack = stack->next;
	}
	stack = pop_stack2 (stack);
	if (before_file)
		before_file->next = stack;
	else
		*lst = stack;
}

/* find '\n' from stack, create function to return n_byte '\n' found  or 0; */
int	find_new_line(t_list *stack, int file)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->file == file)
			i++ ;
		if (stack->item == '\n' && stack->file == file)
			return (i);
		stack = stack->next;
	}
	return (0);
}
