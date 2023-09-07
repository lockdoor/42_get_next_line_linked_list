/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:40:50 by pnamnil           #+#    #+#             */
/*   Updated: 2023/05/13 15:11:41 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	char			item;
	int				file;
}					t_list;

int		get_next_line(int fd, char **line);
t_list	*lstnew(char c, int file);
int		lstadd_back(t_list **lst, t_list *new);
void	lstclear(t_list **lst);
char	*make_str(t_list **stack, int size, int file);
int		find_new_line(t_list *stack, int file);
void	pop_stack(t_list **lst, int file);
t_list	*pop_stack2(t_list *lst);

#endif
