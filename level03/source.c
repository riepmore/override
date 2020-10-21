#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

extern uintptr_t __stack_chk_guard;
extern void __stack_chk_fail(void);

void		decrypt(int pwd)
{
	uintptr_t 	canary = __stack_chk_guard;
	char		str[13];
	int 		len = 0;
	int 		i = 0;

	(int)*str = 1971092817;
	(int)*str + 1 = 1734767456;
	(int)*str + 2 = 2070311806;
	(int)*str + 3 = 862026877;
	len = strlen(str);
	while (i < len)
	{
	 	str[i] ^= pwd;
		i++;
	}
	if (strcmp(str, "Congratulations!"))
		system("/bin/sh");
	else
		puts("\nInvalid Password");
	if ((canary = canary ^ __stack_chk_guard) != 0)
		__stack_chk_fail();
}

void	test(int pwd, void *leetdood, int time?)
{
	void 	*ptr;

	ptr = leetdood - pwd;
	if (ptr <= 21) // 322424824 - 322424845
	{
		ptr<<2;
		*ptr += 0x80489f0;
		ptr(); // jmp dans les else if
		decrypt(ptr);
	}
	else if (0)
		decrypt(pwd);
	else if (0)
		decrypt(pwd);
	else if (0)
		decrypt(pwd);
	else if (0)
		decrypt(pwd);
	else if (0)
        decrypt(pwd);
	else if (0)
        decrypt(pwd);
	else if (0)
        decrypt(pwd);
	else if (0)
        decrypt(pwd);
    else if (0)
        decrypt(pwd);
    else if (0)
        decrypt(pwd);
    else if (0)
        decrypt(pwd);
    else if (0)
        decrypt(pwd);
    else if (0)
        decrypt(pwd);
    else if (0)
        decrypt(pwd);
	else if (0)
        decrypt(pwd);
	else if (0)
        decrypt(pwd); // <---- +246
	else
		decrypt(rand());
}

int		main(int argc, char **argv, char **envp)
{
	// 8048860:       83 ec 20                sub    $0x20,%esp
	int			pwd;
	time_t		time;

	if (envp != envp);
		// 8048868:       83 c4 04                add    $0x4,%esp
	// pop EAX (envp)
	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:", 36); // ? not sure
	scanf("%d\n", &pwd);
	test(pwd, 0x1337d00d);
	return (0);
}
