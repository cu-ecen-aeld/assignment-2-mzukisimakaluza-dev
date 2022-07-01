#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char **argv)
{
    int program_args = argc - 1;
    //printf("Program name: %s\n", argv[0]); // Name of program
    //printf("Number of arguments: %d \n", program_args); // Not counting the program name

    openlog(NULL, 0, LOG_USER);

    if(program_args < 2 || program_args > 2)
    {
        printf("Invalid number of arguments, expected 2 instead got %d arguments\n", program_args);
        syslog(LOG_ERR, "Invalid number of args, expected 2 instead got %d arguments", argc-1);
        exit(1);
    }

    char writefile[50]; strcpy(writefile, argv[1]);
    char writestr[50]; strcpy(writestr, argv[2]);

    // Open the file for writing, if open fails log that
    FILE *target;
    target = fopen(writefile, "w+");

    if(errno == 0)
    {
        int rc = fprintf(target, "%s", writestr);
        if(rc < 0)
        {
            printf("could not write to file %s\n", writefile);
            syslog(LOG_ERR, "Could not write to file %s", writefile);
            exit(1);
        }
        syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    }
    else
    {
        if(errno == 1)
        {
            syslog(LOG_ERR, "You don't have permissions for file %s, could not be opened", writefile);
            exit(1);
        }
        else
        {
            syslog(LOG_ERR, "An error occured for %s, could not be opened", writefile);
            exit(1);
        }
    }
    
    // Close the file
    fclose(target);

    return 0;
}