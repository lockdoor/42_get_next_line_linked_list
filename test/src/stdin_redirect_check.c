#include "libft.h"

int main(void)
{
	char	*line;
	char	*filename = "take_me_to_your_heart.txt";
	char	*usr_name = ft_strcat (USER_D, filename);

	FILE	*file = fopen (usr_name, "w");
	free (usr_name);
	printf ("******************** get next line redirect start **********************\n");
	while (get_next_line (0, &line))
	{
		fprintf (file, "%s\n", line);
		free (line);
	}
	fclose (file);
	printf ("\n===================================\n\n");
	printf ("file: %s\n", filename);
	int res = file_cmp (filename);
	printf ("status: %s\n", res ? "FAIL" : "PASS");
	printf ("\n===================================\n");

	return 0;
}
