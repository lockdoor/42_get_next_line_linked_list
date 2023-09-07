#include "libft.h"

int main(void)
{
    char	*files[] = {
							"my_love.txt",
							"take_me_to_your_heart.txt",
							"when_you_say_nothing_at_all.txt",
							NULL
						};
	printf ("******************** get next line mandatory start **********************\n");
	for (int i = 0; files[i]; i++)
	{
		int res = create_user_file (files[i]);
		if (res == -1)
			printf ("error: on create user file file");
		printf ("\n===================================\n\n");
		printf ("file%d: ", i + 1);
		res = file_cmp (files[i]);
		printf ("status: %s\n", res ? "FAIL" : "PASS");
		printf ("\n===================================\n");
	}
	return (0);
}