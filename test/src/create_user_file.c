#include "libft.h"

int create_user_file(const char *filename)
{
	char	*line;
	char	*src_name = ft_strcat (FILE_D, filename);
	char	*usr_name = ft_strcat (USER_D, filename);
	int		res;

	int		src = open (src_name, O_RDONLY);
	FILE    *user = fopen (usr_name, "w");
	while ((res = get_next_line (src, &line) > 0))
	{
		fprintf(user, "%s\n", line);
		free (line);
	}
	free (src_name);
	free (usr_name);
	close (src);
	fclose (user);
    return (res);
}
