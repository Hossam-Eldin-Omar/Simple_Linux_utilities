#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char**argv)
{
	if(argc == 1)
	{
		if(write(STDOUT_FILENO, "\n", 1) == -1)
	       	{
       			perror("write");
        		exit(EXIT_FAILURE);
    		}
	}
	else
	{
		int it = 1;
		while(it < argc)
		{
			if(write(STDOUT_FILENO, argv[it], strlen(argv[it])) == -1)
               	 	{
                        	perror("write");
                        	exit(EXIT_FAILURE);
                	}
			if (it < argc - 1)
		       	{
                		if (write(STDOUT_FILENO, " ", 1) == -1) 
				{
                    			perror("write");
                    			exit(EXIT_FAILURE);
                		}
            		}
			it++;	
		}

		if (write(STDOUT_FILENO, "\n", 1) == -1)
        	{
                	perror("write");
                	exit(EXIT_FAILURE);
        	}
	}

	return 0;
}
