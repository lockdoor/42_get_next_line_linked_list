#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "../../get_next_line_bonus.h"

# define FILE_D "file/"
# define USER_D "user/"

int		create_user_file(const char *filename);
char	*ft_strcat(const char *s1, const char *s2);
int     file_cmp(const char *filename);

#endif