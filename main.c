// rchaney@pdx.edu

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/param.h>

#include "cmd_parse.h"


// I have this a global so that I don't have to pass it to every
// function where I might want to use it. Yes, I know global variables
// are frowned upon, but there are a couple of times where they can use
// their power for good. This is one.
extern unsigned short isVerbose;

int 
main( int argc, char *argv[] )
{
    int ret = 0;

    simple_argv(argc, argv);
    ret = process_user_input_simple();

    return(ret);
}
