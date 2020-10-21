4294956264
int	auth(char *login, unsigned int serial)
{
	int len; // ebp - 0xc
	int a;	// ebp - 0x10
	int i; // ebp - 0x14

	login[strcspn(login, "\n")] = 0;
	len = strnlen(login, 32);
	if (len > 5)
	{
		if (ptrace(0, 0, 1, 0) == -1) {
			puts("\033[32m.---------------------------."); 
			puts("\033[31m| !! TAMPERING DETECTED !!  |");
			puts("\033[32m'---------------------------'");
			return(1);
		}
		a = login[3] ^ 4919 + 6221293
		i = 0;
		while (i < len)
		{
			if (login[i] <= 31)
				return (1);
			a = a - (((a - ((login[i] ^ a) * 0x88233b2b) / 0x100000000) >> 1 +\
				(((login[i] ^ a) * 0x88233b2b) / 0x100000000)) >> 10) * 1337

			i++;
		}
		if (serial == a)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argc)
{
	char login[32]; //esp + 0x2c
	unsigned int serial; //esp + 0x28

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: "); 
	fgets(login, 32, stdin);
	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", serial);
	if (auth(login, serial) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return(0);
	}
	else
		return (1);
}
