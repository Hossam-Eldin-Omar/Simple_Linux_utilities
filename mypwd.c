#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	 if (argc != 1)
   	 {
        	fprintf(stderr, "Usage: %s\n", argv[0]);
       	     	exit(EXIT_FAILURE);
   	 }

	 char *buf = getcwd(NULL, 0);
	 if(buf == NULL)
	 {
		 perror("getcwd");
		 exit(EXIT_FAILURE);
		 free(buf);
	 }
	 write(STDOUT_FILENO, buf, strlen(buf));	
	 write(STDOUT_FILENO, "\n", 1);
	
	 free(buf);

}

