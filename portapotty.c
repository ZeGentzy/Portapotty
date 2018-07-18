#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void ExampleFn(const char* data)
{
    static void (*fptr_ExampleFn)(const char*) = NULL;
    if (!fptr_ExampleFn) {
        *(void **) (&fptr_ExampleFn) = dlsym(RTLD_NEXT, "ExampleFn");
        if (!fptr_ExampleFn) {
            fprintf(stderr, "Could not find ExampleFn\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Process %d called ExampleFN for %s\n", getpid(), data);
    return fptr_ExampleFn(data);
}
