#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void ExampleFn(const char* data) {
    printf("ExampleFN: %s\n", data);
}
