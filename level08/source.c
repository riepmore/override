#include <stdio.h>
#include <sys/stat.h>
//	value in stack	0x118		0x120			0x128
void	log_wrapper(FILE *fd, char *message, char *filename)
{
	char	towrite[264]; // 0x110

	strcpy(towrite, message);
	strlen(message);
	strlen(filename);
	snprintf(&towrite[strlen(towrite)], 254 - strlen(filename), filename);
	towrite[strcspn(towrite, '\n')] = 0; 
	fprintf(fd, "LOG: %s\n", towrite);
}

// value in stack 0x94		0xa0
int		main(int argc, char **argv)
{
	FILE	*log; //rbp-0x88
	FILE	*file; //rbp-0x80
	FILE	*backup; //rbp - 0x78
	char 	path[64]; //rbp-0x70

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
	}
	if ((log = fopen("./backups/.log", "w")) == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(log, "Starting back up: ", argv[1]);
	if ((file = fopen(argv[1], "r")) == 0)
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	path = "./backup";
	strncat(path, argv[1], 99 - strlen(argv[1]));
	if ((backup == open(path, 0xc1 , S_IRUSR | S_IRGRP)) == 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backup", argv[1]);
		exit(1);
	}
	// boucle while to write in file
	if (fgetc(file) != -1)
	{

	}
}
