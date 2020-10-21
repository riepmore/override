#include <stdio.h>

char		a_user_name[100]; // size to check

int		verify_user_name(char *username)
{
	puts("verifying username....\n");
	return (strncmp(username, "dat_wil\n", 8));
}

int		verify_user_pass(char *password)
{
	return (strncmp(password, "admin\0", 6));
}

int 		main()
{
	// 0x60 args
	char		a_password[64];

	memset(a_password, 0, 16); // 0x1c
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	if (verify_user_name(fgets(a_user_name, 256, stdin)) == 0)
	{
		puts("Enter Password: ");
		fgets(a_password, 100, stdin);
		verify_user_pass(a_password);
		puts("nope, incorrect password...\n");
	}
	else
	{
		puts("nope, incorrect username...\n");
		return (1);
	}
	return (0);
}
