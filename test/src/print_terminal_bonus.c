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

/* main file */
int	main(void)
{
	char			*line;

	int	fd1 = open ("file/my_love.txt", O_RDONLY);
	int	fd2 = open ("file/take_me_to_your_heart.txt", O_RDONLY);
	int	fd3 = open ("file/when_you_say_nothing_at_all.txt", O_RDONLY);
	printf ("================ BONUS ===============\n");
	for (int i = 1; i <= 100; i++)
	{
		if (get_next_line (fd1, &line))
		{
			printf ("%d_line[%2d]: %s\n", fd1, i, line);
			free (line);
		}
		if (get_next_line (fd2, &line))
		{
			printf ("%d_line[%2d]: %s\n", fd2, i, line);
			free (line);
		}
		if (get_next_line (fd3, &line))
		{
			printf ("%d_line[%2d]: %s\n", fd3, i, line);
			free (line);
		}
	}
	printf ("===============================\n\n");
	close (fd1);
	close (fd2);
	close (fd3);
	return (0);
}
