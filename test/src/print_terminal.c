/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamnil <pnamnil@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:40:50 by pnamnil           #+#    #+#             */
/*   Updated: 2023/05/13 15:11:41 by pnamnil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	disp(char *filename)
{
	char	*line;
	int		i = 1;
	int		fd = open (filename, O_RDONLY);
	while (get_next_line (fd, &line))
	{
		printf ("%d_line[%2d]: %s\n", fd, i++, line);
		free (line);
	}
	close (fd);
}

/* main file */
int	main(void)
{
	char	*file1 = "file/my_love.txt";
	char	*file2 = "file/take_me_to_your_heart.txt";
	char	*file3 = "file/when_you_say_nothing_at_all.txt";
	printf ("================ file1 ===============\n");
	disp (file1);
	printf ("\n================ file2 ===============\n");
	disp (file2);
	printf ("\n================ file3 ===============\n");
	disp (file3);
	printf ("===============================\n\n");
	return (0);
}
