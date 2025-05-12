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
                fprintf(stderr,"Usage: %s source_file destination_file\n", argv[0]);
                exit(EXIT_FAILURE);
        }
	if (rename(argv[1], argv[2]) == 0)
       	{
        	return 0;
    	}

	int src_fd = open(argv[1], O_RDONLY);
   	if (src_fd < 0) 
	{
        	perror("open (source)");
        	exit(EXIT_FAILURE);
    	}

	int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    	if (dest_fd < 0) 
	{
        	perror("open (destination)");
        	close(src_fd);
        	exit(EXIT_FAILURE);
    	}

    	ssize_t bytes_read;
    	while ((bytes_read = read(src_fd, buf, COUNT)) > 0) 
	{
        	ssize_t bytes_written = write(dest_fd, buf, bytes_read);
        	if (bytes_written != bytes_read) 
		{
            		perror("write");
        	    	close(src_fd);
	            	close(dest_fd);
            		exit(EXIT_FAILURE);
        	}
    	}

	if (bytes_read < 0){
        	perror("read");
	        close(src_fd);
	        close(dest_fd);
	        exit(EXIT_FAILURE);
    	}

	close(src_fd);
    	close(dest_fd);

    	if (unlink(argv[1]) < 0) 
	{
        	perror("unlink");
	        exit(EXIT_FAILURE);
    	}
	return 0;

}
