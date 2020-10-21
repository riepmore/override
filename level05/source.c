#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void	main()
{
	char buf[100]; // esp+ 0x28
	int i; //esp + 0x8c ?

	fgets(buf, 100, stdin);
	i = 0;
	if (strlen(buf) > 0)//main+186
	{
		while (i < strlen(buf))
		{
			tolower(buf[i]);
			i++;
		}
	}
	printf(buf);
	exit(0);
}
