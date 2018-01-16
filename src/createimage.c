#include <assert.h>
#include <elf.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_FILE "image"
#define ARGS "[--extended] [--vm] <bootblock> <executable-file> ..."


/* Variable to store pointer to program name */
char *progname; 

/* Variable to store pointer to the filename for the file being read. */
char *elfname;

/* Structure to store command line options */
static struct {
    int vm;
    int extended;
} options;

/* prototypes of local functions */
static void create_image(int nfiles, char *files[]);
static void error(char *fmt,...);

int main(int argc, char **argv)
{
    /* Process command line options */
    progname = argv[0];
    options.vm = 0;
    options.extended = 0;
    while ((argc > 1) && (argv[1][0] == '-') && (argv[1][1] == '-')) 
    {
        char *option = &argv[1][2];

        if (strcmp (option, "vm") == 0) {
            options.vm = 1;
        } else if (strcmp (option, "extended") == 0) {
            options.extended = 1;
        } else {
            error ("%s: invalid option\nusage: %s %s\n", progname, progname, ARGS);
        }
        argc--;
        argv++;
    }
    if (options.vm == 1) {
      /* This option is not needed in project 1 so we doesn't bother
       * implementing it*/
      error ("%s: option --vm not implemented\n", progname);
    }
    if (argc < 3) {
        /* at least 3 args (createimage bootblock kernel) */
        error ("usage: %s %s\n", progname, ARGS);
    }
    create_image (argc - 1, argv + 1);
    return 0;
}

static void create_image(int nfiles, char *files[])
{
    /* This is where you should start working on your own implemtation
     * of createimage.  Don't forget to structure the code into
     * multiple functions in a way whichs seems logical, otherwise the
     * solution will not be accepted. */

    fprintf (stderr, "This version of %s doesn't do anything.\n", progname);
    exit (-1);
}


/* print an error message and exit */
static void error(char *fmt, ...)
{
    va_list args;

    va_start (args, fmt);
    vfprintf (stderr, fmt, args);
    va_end (args);
    if (errno != 0) {
        perror (NULL);
    }
    exit (EXIT_FAILURE);
}

