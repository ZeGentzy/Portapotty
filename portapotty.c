#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

int c = 0;

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

    printf("Process %d called ExampleFN for %s, %i\n", getpid(), data, c);
    ++c;
    return fptr_ExampleFn(data);
}
