#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void ExampleFn(const char* data) {
    printf("ExampleFN: %s\n", data);
}

void ExampleFn2(const char* data) {
    printf("ExampleFN2: %s\n", data);
}
