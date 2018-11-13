#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#define BUFFER_SIZE 100
int main(){
	char buff;
	int count = 0;
	int w_result;
	int a=0;
	
	int fd = open("10l.c", O_APPEND);
	int result = 1;
	
	while(result > 0){
		if(buff=='\n'){
			count++;
			if(count==10){
				break;
			}

		}
		result = read(fd, &buff, 1);
		int written = 0;

		while(written < result){
			w_result = write(STDOUT_FILENO, &buff, result - written);

			written += w_result;
			
		}
		
	}
}
