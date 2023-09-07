#include "libft.h"

int	file_cmp(const char *filename)
{
	char	*src_name = ft_strcat (FILE_D, filename);
	char	*usr_name = ft_strcat (USER_D, filename);
	FILE	*fp1, *fp2;
	int		ch1, ch2;

	fp1 = fopen (src_name, "r");
	if (fp1 == NULL)
	{
		printf("Failed to open %s.\n", src_name);
        return -1;
	}

	fp2 = fopen (usr_name, "r");
	if (fp2 == NULL)
	{
        printf("Failed to open %s.\n", usr_name);
        fclose(fp1);
        return -1;
    }

	ch1 = getc(fp1);
	ch2 = getc(fp2);
	while (ch1 != EOF && ch2 != EOF && ch1 == ch2)
	{
		ch1 = getc(fp1);
		ch2 = getc(fp2);
	}

	fclose(fp1);
    fclose(fp2);
	free (src_name);
	free (usr_name);

	if (ch1 == ch2)
	{
        printf ("Files are identical.\n");
        return 0;
    } else {
        printf ("Files are different.\n");
        return 1;
    }

}