//------------------------------------------------------------------------
// NAME: Viktor Vladimirov
// CLASS: XIa
// NUMBER: 5
// PROBLEM: #1
// FILE NAME: headH.c
// FILE PURPOSE:
// Implementation of the UNIX head function
// that STDOUTs the first 10 lines of files
// passed as program arguments
// 
//------------------------------------------------------------------------
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 100
#include<string.h>
int main(int argc, char **argv){
	char buff;
	int i = 0;
	int fd = open("a.txt", O_APPEND);
	int result = 1;
	
	/*while(result > 0 && i < 10)
	{
		result = read(fd, &buff, 1);
		write(STDOUT_FILENO, &buff, result);
		if(buff=='\n')
			i++;
	}*/
	for(int k = 1; k < argc; k++)
	{
		if(argc>2)
		{	
			write(STDOUT_FILENO, "==> ", 4);
			write(STDOUT_FILENO, argv[k], strlen(argv[k]));
			write(STDOUT_FILENO, " <==\n", 5);
		}
		fd = open(argv[k], O_APPEND);
		i = 0;
		result = 1;
		while(result > 0 && i < 10)
		{
			result = read(fd, &buff, 1);
			write(STDOUT_FILENO, &buff, result);
			if(buff=='\n')
				i++;
		}
		if(k+1!=argc)
				write(STDOUT_FILENO, "\n", 1);
	}
}
