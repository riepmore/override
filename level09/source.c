#include <stdio.h>

void	secret_backdoor()
{
	char	s[128];

	fgets(s, 128, stdin);
	system(s);
}

void	set_username(char *user)
{
	int		i;

	i = 0;
	puts(">: Enter your username");
	printf(">>: "); // bufferized?
	fgets(user, 128, stdin);
	while (i < 40 && user[i] != '\0') // Copy 41 but user is an array of 40, so we can overwrite the len var in handle_msg()
	{
		i++;
	}
	printf(">: Welcome, %s", user);
}

void	set_msg(char *data, int *len)
{
	char	buf[1024];

	memset(buf, 0, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: "); // bufferized?
	fgets(buf, 1024, stdin);
	strncpy(data, buf, len);
}

void	handle_msg()
{
	char 	msg[140];
	char 	user[40];
	int 	len;

	memset(user, 0, 40); // equivalent
	len = 140;
	set_username(&user);
	set_msg(&msg, &len);
	puts(">: Msg sent!");
}

int		main()
{
	puts("\
	--------------------------------------------\
	|   ~Welcome to l33t-m$n ~    v1337        |\
	--------------------------------------------\
	");
	handle_msg();
	return (0);
}
