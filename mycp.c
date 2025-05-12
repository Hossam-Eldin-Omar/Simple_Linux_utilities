#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define COUNT 100

int main(int argc, char **argv)
{
        char buf[COUNT];

        if(argc != 3)
        {
                fprintf(stderr,"Usage: %s file-name-1 file-name-2\n", argv[0]);
                exit(EXIT_FAILURE);
        }
	int fd[2];

        fd[0] = open(argv[1], O_RDONLY);
	if(fd[0] < 0)
	{
		perror("open (source)");
                exit(EXIT_FAILURE);
	}
	fd[1] = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	if (fd[1] < 0) 
    	{
        	perror("open (destination)");
        	close(fd[0]);
        	exit(EXIT_FAILURE);
    	}
	int num_read;
	while((num_read = read(fd[0], buf, COUNT)) > 0)
	{
		if(write(fd[1], buf, num_read) < 0)
		{
		    perror("write");
		    close(fd[0]);
		    close(fd[1]);
		    exit(EXIT_FAILURE);
		}
	}
	if (num_read < 0) 
	{
		perror("read");
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
    	}

	int len = sizeof(fd) / sizeof(fd[0]);
	for(int i = 0;i<len;i++)
	{
		close(fd[i]);
	}
	
	return 0;
}                                                                                                                                       
