#include "libft.h"

int main(void)
{
    char	*files[] = {
							"my_love.txt",
							"take_me_to_your_heart.txt",
							"when_you_say_nothing_at_all.txt",
							NULL
						};
	char	*line;
	char	*src_name;
	char	*usr_name;

	printf ("******************** get next line bonus start **********************\n");

	/* open src file */
	int		len = (sizeof(files) / sizeof(*files)) - 1;
	int		src[len];
	for (int i = 0; files[i]; i++)
	{
		src_name = ft_strcat (FILE_D, files[i]);
		src[i] = open (src_name, O_RDONLY);
		free (src_name);
	}

	/* open usr file */
	FILE	*usr[len];
	for (int i = 0; files[i]; i++)
	{
		usr_name = ft_strcat (USER_D, files[i]);
		usr[i] = fopen (usr_name, "w");
		free (usr_name);
	}

	/* copy src to usr */
	for (int i = 1; i <= 25; i++)
	{
		for (int n = 0; n < len; n++)
		{
			if (get_next_line (src[n], &line))
			{
				fprintf(usr[n], "%s\n", line);
				free (line);
			}
		}
	}

	/* close file */
	for (int i = 0; files[i]; i++)
	{
		close (src[i]);
		fclose (usr[i]);
	}

	/* compair */
	for (int i = 0; files[i]; i++)
	{
		printf ("\n===================================\n\n");
		printf ("file%d: ", i + 1);
		int res = file_cmp (files[i]);
		printf ("status: %s\n", res ? "FAIL" : "PASS");
		printf ("\n===================================\n");
	}
	return (0);
}
