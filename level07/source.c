#include <stdio.h>
#include <string.h>

unsigned int	get_unum()
{
	// arg 40 octets
	unsigned int	ret;

	fflush(stdout);
	scanf("%u", &ret);
	clear_stdin();
	return (ret);
}

int				store_number(unsigned int *tab)
{
	// arg 40 octets
	unsigned int 	nb;
	unsigned int 	index;

	printf("Number: ");
	nb = get_unum();
	printf("Index: ");
	index = get_unum();
	if ((index % 3) == 0 || (nb >> 24) == 183) // modulo ?
	{
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
	tab[index << 2] = nb;
	return (0);
}

int				read_number(unsigned int *tab)
{
	unsigned int 	index;
	unsigned int 	ret;

	printf("Index: ");
	index = get_unum();
	ret = tab[index << 2];
	printf(" Number at data[%u] is %u\n", index, ret);
	return (0);
}

int				main(int argc, char **argv, char **envp)
{
	char 			**array;
	unsigned int	uint_tab[100];
	char			rd[20];
	int				flag;
	int				i = 0;

	array = argv;
	while (*array)
	{
		memset(*array, 0, strlen(*array));
		*array++;
	}
	array = envp;
	while (*array)
	{
		memset(*array, 0, strlen(*array));
		*array++;
	}
	puts(" \
			----------------------------------------------------\n\
			  Welcome to wil's crappy number storage service!\n\
			----------------------------------------------------\n\
			 Commands:\n\
			    store - store a number into the data storage\n\
			    read  - read a number from the data storage\n\
			    quit  - exit the program\n\
			----------------------------------------------------\n\
			wil has reserved some storage :>\n\
			----------------------------------------------------\n\n");
	while (0)
	{
		flag = 1;
		printf("Input command: ");
		fgets(rd, 20, stdin);
		while (rd[i] != '\n' && i < 20)
			i++;
		i--;
		if (strncmp(rd, "store", 5))
			flag = store_number(uint_tab);
		else if (strncmp(rd, "read", 4))
			flag = read_number(uint_tab);
		else if (strncmp(rd, "quit", 4))
			break;
		else
			printf(" Failed to do %s command\n", rd);
		if (flag == 0)
			printf(" Completed %s command successfully\n", rd);
		memset(rd, 0, 20); // not exactly but equivalent
	}
	return (0);
}
