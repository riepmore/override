int	main(int argc, char **argv)
{
	int value;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", value);
	if (value == 5276)
	{
		puts("\nAuthenticated!");
		system("/bin/sh");
	}
	puts("\nInvalid Password!");
	return (1);
}
