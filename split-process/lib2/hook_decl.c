#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// Hook libraries
#include <gl_hook_lib.c>
#include <glx_hook_lib.c>

// GLOBAL VARS

FILE *fp;

static void init () __attribute__((constructor));
static void fini () __attribute__((destructor));

static void init()
{
    printf("RAPTURE: Stub library init\n");
}

static void fini()
{
    printf("RAPTURE: Stub library fini\n");
}
