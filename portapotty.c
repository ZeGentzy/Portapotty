#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void ExampleFn(const char* data) {
    printf("Process %d called ExampleFN for %s\n", getpid(), data);
    void (*real_ExampleFn)(const char*);
    *(void **) (&real_ExampleFn) = dlsym(RTLD_DEFAULT, "ExampleFn");
    if (!real_ExampleFn) {
        fprintf(stderr, "LIB: Failed to load ExampleFn\n");
        exit(EXIT_FAILURE);
    }
    return real_ExampleFn(data);
}
